<?php
	/**
 * Implementation of hook_menu().
 */
function TPA_poi_content_menu() {
  $items['feeds/subcategories.xml'] = array(
      'page callback' => 'TPA_poi_content_subcategory_feed',
      'access arguments' => array('access content'),
  );

  $items['feeds/pois.xml'] = array(
      'page callback' => 'TPA_poi_content_poi_feed',
      'access arguments' => array('access content'),
  );

  return $items;
}    