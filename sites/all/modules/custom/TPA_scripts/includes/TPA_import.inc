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
 		/* set php .ini variables to avoid import overload */
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
	  foreach( $nodes as $node ) {
	  	// Find subcategory entity id, using id from feed
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
		  	node_save( $node );
		  }
	  }
 	}