<?php

	/**
	 * Function to create the subcategories xml feed
	 */
	function TPA_poi_content_subcategory_feed() {
		// Xml http header
		drupal_add_http_header('Content-Type: text/xml');

		// Print the feed
		print '<pointTypes>';
		print TPA_poi_content_all_point_type_elements();
		print '</pointTypes>';

		// Prevents page templating and theming, we want raw xml data
		drupal_exit();
	}

	/**
	 * Function to create all xml point type elements of the subcategory feed
	 */
	function TPA_poi_content_all_point_type_elements() {
		// Find all subcategory nodes
		$query = new EntityFieldQuery;
	  $result = '';
	  $result = $query
	    ->entityCondition( 'entity_type', 'node' )
	    ->entityCondition( 'bundle', 'subcategory' )
	    ->propertyCondition( 'status', 1 )
	    ->execute();
	  $nodes = entity_load('node', array_keys($result['node']));
	  
	  
	  // Loop through all subcategory nodes and create an xml pointType for each
	  $point_type_xml = '';
	  foreach( $nodes as $node ) {
	  	//var_dump( $node );
	  	
	  	// Get variables from node
	  	$closedImage = file_create_url($node->field_list_closed_icon['und'][0]['uri']); 		// List image closed
	  	$closedMapImage = file_create_url($node->field_map_closed_icon['und'][0]['uri']);  	// Closed map image
			$image = file_create_url($node->field_list_icon['und'][0]['uri']); 									// List image
			$mapImage = file_create_url($node->field_map_icon['und'][0]['uri']); 								// Map image
			$errorReportEnabled = $node->field_activate_error_reporting['und'][0]['value'] == 1 ? 'true' : 'false';
			$picturesEnabled = $node->field_activate_images['und'][0]['value'] == 1 ? 'true' : 'false';
			$name = htmlspecialchars( $node->title, ENT_QUOTES );
			
			// The xml
			$point_type_xml .= '
				  <pointType errorReportEnabled="' . $errorReportEnabled . '" picturesEnabled="' . $picturesEnabled . '" 
				  					 name="' . $name . '" id="' . $node->nid . '">
				    <closedImage imageUrl="' . $closedImage . '"/>
				    <closedMapImage imageUrl="' . $closedMapImage . '"/>
				    <image imageUrl="' . $image . '"/>
				    <mapImage imageUrl="' . $mapImage . '"/>
				  </pointType>';
		}

		return $point_type_xml;
	}