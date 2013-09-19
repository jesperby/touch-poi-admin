<?php

	global $tmp_year;  // Arbitrary year used to create unix timestamps for dates/times specified without year
	$tmp_year = '2013';

	error_reporting(E_ALL);
	ini_set('display_errors', '1');

	/**
	 * Function to create the poi xml feed
	 */
	function TPA_poi_content_poi_feed() {
		// Xml http header
		drupal_add_http_header('Content-Type: text/xml');

		// Print the feed
		print '<points>';
		print TPA_poi_content_all_poi_xml_elements();
		print '</points>';

		// Prevents page templating and theming, we want raw xml data
		drupal_exit();
	}

	/**
	 * Function to create all xml poi type elements of the subcategory feed
	 */
	function TPA_poi_content_all_poi_xml_elements() {
	
		// Extract info about poi categories	
		$poi_categories = TPA_poi_content_poi_category_info();
	
		// Loop all poi nodes and create xml
		$query = new EntityFieldQuery;
	  $result = '';
	  $result = $query
	    ->entityCondition( 'entity_type', 'node' )
	    ->entityCondition( 'bundle', 'poi' )
	    ->propertyCondition( 'status', 1 )
	    ->execute();
	  $nodes = entity_load('node', array_keys($result['node']));
	  
	  // Loop through all poi nodes and create an xml point element for each
	  $point_xml = '';
	  $i = 0;
	  foreach( $nodes as $node ) { 	
	  	$ts = TPA_poi_content_unix_timestamps( $node );

	  	/*
	  	
	  	$active = TPA_poi_content_poi_active( $node, $poi_categories );	  
	  	
	  	//$active = 'false';
	  	$address = htmlspecialchars( $node->field_adress['und'][0]['value'], ENT_QUOTES );
	  	$imageUrl = file_create_url($node->field_poi_image['und'][0]['uri']);
	  	
			$longitude = $node->field_geolocation['und'][0]['lng'];
			$langitude = $node->field_geolocation['und'][0]['lat'];

	  	$description = htmlspecialchars( $node->body['und'][0]['value'], ENT_QUOTES );
	  	$name = htmlspecialchars( $node->title, ENT_QUOTES );
	  	$id = $node->nid;

	  	// TODO - Calculate based on open season times
	  	$openTime = "09:00";
	  	$closeTime = "21:00";

			$point_xml .= '
				<point 	type="' . $type . '" longitude="' . $longitude . '" latitude="' . $langitude . '" active="' . $active . '" 
								id="' . $id . '" 
								name="' . $name . '" address="' . $address . '" openTime="' . $openTime . '" closeTime="' . $closeTime . '">
					<description>' . $description . '</description>
					<image imageUrl="' . $imageUrl . '"/>
				</point>
			';
			*/
		}

		return $point_xml;
	}


	/**
	 * Function that returns array with poi category info
	 */
	function TPA_poi_content_poi_category_info() {
		// Store closed and seasons activated for all poi category types
		// Needed to determine whether a poi is closed or open
		$query = new EntityFieldQuery;
	  $result = '';
	  $result = $query
	    ->entityCondition( 'entity_type', 'node' )
	    ->entityCondition( 'bundle', 'subcategory' )
	    ->propertyCondition( 'status', 1 )
	    ->execute();
	  $nodes = entity_load('node', array_keys($result['node']));
	  
	  
	  // Loop through all poi category nodes and store closable and season info
	  $poi_categories = array();
	  foreach( $nodes as $node ) { 	
	  	$closable_activated = $node->field_activate_closable['und'][0]['value'] == 0 ? 'false' : 'true';
	  	$seasons_activated = $node->field_activate_seasons['und'][0]['value'] == 0 ? 'false' : 'true';

	  	$poi_categories[$node->nid] = array( 	'closable_activated' => $closable_activated, 
	  																				'seasons_activated' => $seasons_activated );
	  }

	  return $poi_categories;
	}


	/**
	 * Function to determine whether a poi is active
	 */
	function TPA_poi_content_poi_active( $node, $poi_categories ) {
  	
  	// Is closable and/or seasons activated?
  	$poi_category = $node->field_subcategory['und'][0]['target_id'];
  	$closable_activated = $poi_categories[$poi_category]['closable_activated'];
  	$seasons_activated = $poi_categories[$poi_category]['seasons_activated'];

  	// We consider the poi open, unless closed by either closed radio button or season open times
  	$active = 'true';

  	// Closed using the radio button?
  	if( $closable_activated ) {
  		if( $node->field_closed['und'][0]['value'] == 1 ) {
  			$active = 'false';
  		}
  	}

  	// Closed because outside season opening times?
  	if( $seasons_activated ) {
			$ts = TPA_poi_content_unix_timestamps( $node );
		
			// Is poi open for autumn?
			$poi_open_for_autumn = false;
			if( $ts['autumn_dates_set'] && $ts['autumn_times_set'] ) {
	  		if( $ts['current_date'] >= $ts['autumn_start_date'] && $ts['current_date'] <= $ts['autumn_end_date'] &&
	  				$ts['current_time'] >= $ts['autumn_start_time'] && $ts['current_time'] <= $ts['autumn_end_time'] ) {
	  			$poi_open_for_autumn = true;
	  		}
  		}

  		// Is poi open for spring
  		$poi_open_for_spring = false;
  		if( $ts['spring_dates_set'] && $ts['spring_times_set'] ) {
  			if( $ts['current_date'] >= $ts['spring_start_date'] && $ts['current_date'] <= $ts['spring_end_date'] &&
  					$ts['current_time'] >= $ts['spring_start_time'] && $ts['current_time'] <=	 $ts['spring_end_time'] ) {
  				$poi_open_for_spring = true;
  			}	
  		}

  		if( !$poi_open_for_autumn && !$poi_open_for_spring) {
  			$active = 'false';
  		}

  	}

  	return $active;
	}


	/**
	 * Function to create array with all relevant node dates and times as unix timestamps
	 * NOTE! For dates provided by the Drupal date module, we replace year with current year
	 * as module didn't support month and date only.
	 */
	function TPA_poi_content_unix_timestamps( $node ) {
		/*
		$timestamps = array();
		date_default_timezone_set('UTC');
		global $tmp_year;

		if( $node->nid == 1128 ) {
  		//print_r( $node->field_field_spring_start_month );
			//print_r( $node->field_field_spring_start_day  );
			//print_r( $node->field_field_spring_start_hour );
			//print_r( $node->field_field_spring_start_minute  );
			

			// Spring date
			if( isset( $node->field_field_spring_start_month ) &&
					isset( $node->field_field_spring_start_day ) &&
					isset( $node->field_field_spring_end_month ) && 
					isset( $node->field_field_spring_end_day ) ) {
				print "HERE";				

				$timestamps['spring_dates_set'] = true;

				$start_month = $node->field_field_spring_start_month['und'][0]['value'];
				$start_day = $node->field_field_spring_start_day['und'][0]['value'];
				$end_month = $node->field_field_spring_end_month['und'][0]['value'];
				$end_day = $node->field_field_spring_end_day['und'][0]['value'];

				print "start month" . $start_month . "\r\n";
				print "start day" . $start_day . "\r\n";
				print "end month" . $end_month . "\r\n";
				print "end day" . $end_day . "\r\n";

				$spring_start_date = date("Y") . mb_substr( $node->field_spring_dates['und'][0]['value'], 4 );  		
				$timestamps['spring_start_date'] = strtotime( $spring_start_date );

				
			} else {
				//$timestamps['spring_dates_set'] = false;
			}
			die;
		} 
		*/
		/*
		
		*/

		/*
		// Autumn date
		if( isset( $node->field_autumn_dates['und'][0] ) ) {
			$timestamps['autumn_dates_set'] = true;
			$autumn_dates = $node->field_autumn_dates['und'][0];
			
			// Autumn start date
			$autumn_start_date = date("Y") . mb_substr( $node->field_autumn_dates['und'][0]['value'], 4 );  		
			$timestamps['autumn_start_date'] = strtotime( $autumn_start_date );

			// Autumn end date
			$autumn_end_date = date("Y") . mb_substr( $node->field_autumn_dates['und'][0]['value2'], 4 );  		
			$timestamps['autumn_end_date'] = strtotime( $autumn_end_date );
		} else {
			$timestamps['autumn_dates_set'] = false;
		}
		
		// Spring date
		if( isset( $node->field_spring_dates['und'][0] ) ) {
			$timestamps['spring_dates_set'] = true;
			$spring_dates = $node->field_spring_dates['und'][0];
			
			// Spring start date
			$spring_start_date = date("Y") . mb_substr( $node->field_spring_dates['und'][0]['value'], 4 );  		
			$timestamps['spring_start_date'] = strtotime( $spring_start_date );

			// Spring end date
			$spring_end_date = date("Y") . mb_substr( $node->field_spring_dates['und'][0]['value2'], 4 );  		
			$timestamps['spring_end_date'] = strtotime( $spring_end_date );
		} else {
			$timestamps['spring_dates_set'] = false;
		}

		// Autumn time
		if( isset( $node->field_autumn_times['und'][0] ) ) {
			$timestamps['autumn_times_set'] = true;
			$autumn_times = $node->field_autumn_times['und'][0];
			
			// Autumn start time
			$autumn_start_time = date("Y-m-d") . mb_substr( $node->field_autumn_times['und'][0]['value'], 10 ); 
			$timestamps['autumn_start_time'] = strtotime( $autumn_start_time );


			// Autumn end time
			$autumn_end_time = date("Y-m-d") . mb_substr( $node->field_autumn_times['und'][0]['value2'], 10 ); 
			$timestamps['autumn_end_time'] = strtotime( $autumn_end_time );
		} else {
			$timestamps['autumn_times_set'] = false;
		}

		// Spring time
		if( isset( $node->field_spring_times['und'][0] ) ) {
			$timestamps['spring_times_set'] = true;
			$spring_times = $node->field_spring_times['und'][0];
			
			// Spring start time
			$spring_start_time = date("Y-m-d") . mb_substr( $node->field_spring_times['und'][0]['value'], 10 ); 
			$timestamps['spring_start_time'] = strtotime( $spring_start_time  );

			// Spring end time
			$spring_end_time = date("Y-m-d") . mb_substr( $node->field_spring_times['und'][0]['value2'], 10 ); 
			$timestamps['spring_end_time'] = strtotime( $spring_end_time );
		} else {
			$timestamps['spring_times_set'] = false;
		}
		*/

		// Current date / time
		$timestamps['current_date'] = strtotime(date('Y-m-d'));	
		$timestamps['current_time'] = strtotime(date('H:i'));	

		return $timestamps;
	}