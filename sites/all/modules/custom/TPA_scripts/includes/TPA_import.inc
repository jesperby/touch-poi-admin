<?php
	/**
 	* @file
 	* Handle import of pois and their categories
 	*/

 	/* 
 	 * Scripts to adjust pois after initial import from old feed
 	 * Note - VERY internal, assumes temporary fields which since have been removed
 	 */
 	function TPA_import_adjust_pois() {
 		// set php .ini variables to avoid import overload
	  set_time_limit(100000);
	  ini_set('memory_limit', '-1');

	  // Find all nodes of type poi
	  $query = new EntityFieldQuery;
	  $result_node = '';
	  $result_node = $query
	    ->entityCondition( 'entity_type', 'node' )
	    ->entityCondition( 'bundle', 'poi' )
	    ->propertyCondition( 'status', 1 )
	    ->execute();

	  // Update all poi nodes
	  $nodes = entity_load('node', array_keys($result_node['node']));
	  $i = 0;
	  foreach( $nodes as $node ) {

	  	if( 1 ) {
		  	print $node->title . "\r\n";

		  	// Update subcategory
			  $query = new EntityFieldQuery;
			  $subcategory_node_ids = '';
			  $subcategory_node_ids = $query
			    ->entityCondition( 'entity_type', 'node' )
			    ->entityCondition( 'bundle', 'subcategory' )
			    ->propertyCondition( 'status', 1 )
			    ->fieldCondition( 'field_type', 'value', $node->field_subcategory_type['und'][0]['value'] )
			    ->execute();
			  $subcategory_nodes = entity_load('node', array_keys($subcategory_node_ids['node']));
			  foreach( $subcategory_nodes as $subcategory_node ) {
			  	$node->field_subcategory['und'][0]['target_id'] = $subcategory_node->nid;
			  	
			  }

			  // Update field closed
			  if( $node->field_not_closed_str['und'][0]['value'] == 'true' ) {
			  	$node->field_closed['und'][0]['value'] = 0;
			  } else {
			  	$node->field_closed['und'][0]['value'] = 1;
			  }

			  // Update image
			  // Initialize empty file
		    $file = (object)array();

		    // Get news image directly from espråk via http
		    //$esprak_image_path = $row->xml->link;
		    $image_path = $node->field_poi_image_str['und'][0]['value'];
		    $image_url_exploded = explode( "/", $image_path );
		    $i = sizeof( $image_url_exploded ) - 1;
		    $image_name = $image_url_exploded[$i];

		    //print "before file_get_contents\r\n";
		    if( TPA_import_http_file_exists( $image_path ) ) {
		      $image_raw = file_get_contents( $image_path );
		    } else {
		      $image_raw = FALSE;
		    }

		    if( $image_raw ) {

		      // Save image in Drupal file system

		      // Rel path
		      $file_img_rel_path = $image_name;

		      // Temp rel path
		      $file_img_tmp_rel_path = 'tmp/' . $image_name;

		      // Drupal tmp path
		      $tmp_dest = file_build_uri( $file_img_tmp_rel_path );

		      // Drupal path
		      $dest = file_build_uri( $file_img_rel_path );

		      // Save file
		      file_save_data($image_raw, $tmp_dest, FILE_EXISTS_REPLACE);

		      // File ok?
		      if( !file_exists( $tmp_dest) || !filesize( $tmp_dest) || filesize( $tmp_dest ) == 0 ) {
		        // Do nothing
		      } else { 
		        // Create managed File object and associate with Image field.
		        $file = (object) array(
		          'uid' => 1,
		          'uri' => $tmp_dest ,
		          'filemime' => file_get_mimetype( $tmp_dest  ),
		          'status' => 1,
		        );


		        // Copy from tmp to permanent directory
		        $file = file_move( $file, $dest, FILE_EXISTS_REPLACE );

		        $node->field_poi_image[LANGUAGE_NONE][0] = (array)$file;
		      }
		    }

			  node_save( $node );
			}

			$i++;
	  }
 	}

 	/**
 	 * Function to read from read an store lat lon in already existing poi nodes
 	 * Used when we replaced float field with the geolocation field from geolocation module
 	 */
 	function replace_lat_lon() {
 		set_time_limit(100000);
	  ini_set('memory_limit', '-1');

	  // Find all nodes of type poi
	  $query = new EntityFieldQuery;
	  $result_node = '';
	  $result_node = $query
	    ->entityCondition( 'entity_type', 'node' )
	    ->entityCondition( 'bundle', 'poi' )
	    ->propertyCondition( 'status', 1 )
	    ->execute();

	  // Update all poi nodes
	  $nodes = entity_load('node', array_keys($result_node['node']));
	  $i = 0;
	  foreach( $nodes as $node ) {
	  	$node->field_geolocation['und'][0]['lat'] = $node->field_latitude['und'][0]['value'];
	  	$node->field_geolocation['und'][0]['lng'] = $node->field_longitude['und'][0]['value'];

	  	node_save($node);
	  }
 	}


	/**
	 * Function that checks if a file exists on given url
	 */
	function TPA_import_http_file_exists($url)
	{
	    $f=@fopen($url,"r");
	    if($f)
	    {
	        fclose($f);
	        return true;
	    }
	    return false;
	}
