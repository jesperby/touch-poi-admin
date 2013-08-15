<?php

	/**
	 * Function to create the poi xml feed
	 */
	function TPA_poi_content_poi_feed() {
		// Xml http header
		drupal_add_http_header('Content-Type: text/xml');

		// Print the feed
		print '<points>';
		print TPA_poi_content_all_point_elements();
		print '</points>';

		// Prevents page templating and theming, we want raw xml data
		drupal_exit();
	}

	/**
	 * Function to create all xml point type elements of the subcategory feed
	 */
	function TPA_poi_content_all_point_elements() {
		
		// Find all poi nodes
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
	  foreach( $nodes as $node ) {
	  	//var_dump( $node );
	  	
	  	$address = $node->field_adress['und'][0]['value'];
	  	$imageUrl = file_create_url($node->field_poi_image['und'][0]['uri']);
	  	$type = $node->field_subcategory['und'][0]['target_id'];
	  	$active = $node->field_closed['und'][0]['value'] == 1 ? 'false' : 'true';
	  	$longitude = $node->field_longitude['und'][0]['value'];
	  	$langitude = $node->field_latitude['und'][0]['value'];
	  	$description = htmlspecialchars( $node->body['und'][0]['value'], ENT_QUOTES );
	  	$name = htmlspecialchars( $node->title, ENT_QUOTES );
	  	$id = $node->nid;
	  	//$point_xml = $name;
	  	
	  	// TODO - Calculate based on open season times
	  	$openTime = "09:00";
	  	$closeTime = "21:00";


	  	/*
	  	// Get variables from node
	  	$closedImage = file_create_url($node->field_list_closed_icon['und'][0]['uri']); 		// List image closed
	  	$closedMapImage = file_create_url($node->field_map_closed_icon['und'][0]['uri']);  	// Closed map image
			$image = file_create_url($node->field_list_icon['und'][0]['uri']); 									// List image
			$mapImage = file_create_url($node->field_map_icon['und'][0]['uri']); 								// Map image
			$errorReportEnabled = $node->field_activate_error_reporting['und'][0]['value'] == 1 ? 'true' : 'false';
			$picturesEnabled = $node->field_activate_images['und'][0]['value'] == 1 ? 'true' : 'false';
			*/

			
			$point_xml .= '
				<point 	type="' . $type . '" longitude="' . $longitude . '" latitude="' . $langitude . '" active="' . $active . '" 
								id="' . $id . '" 
								name="' . $name . '" address="' . $address . '" openTime="' . $openTime . '" closeTime="' . $closeTime . '">
					<description>' . $description . '</description>
					<image imageUrl="' . $imageUrl . '"/>
				</point>
			';
			

			/*
			// The xml
			$point_xml .= '
			  <point 	type="' . $type . '" longitude="' . $longitude . '" latitude="' . $langitude . '" active="' . $active . '" 
			  				name="' . $name . '"   address="' . $address . '" openTime="' . $openTime . '" closeTime="' . $closeTime . '">
					<description>' . $description . '</description>
					<image imageUrl="' . $imageUrl . '"/>
				</point>';
			*/
		}

		return $point_xml;
	}