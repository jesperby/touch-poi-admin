<?php

/**
 * Implementation of hook_block_view().
 */
function TPA_poi_content_block_view($delta = '') {
	$block = '';
  switch ($delta) {
    case 'TPA_add_poi_link':
      $block['subject'] = '';
      $block['pages'] = 'pois';
      $link_text = t('Add poi');
      $block['content'] = l( $link_text, 'node/add/poi');
      break;
    case 'TPA_add_subcategory_link':
      $block['subject'] = '';
      $block['pages'] = 'subcategories';
      $link_text = t('Add subcategory');
      $block['content'] = l( $link_text, 'node/add/subcategory');
      break;
    case 'TPA_add_category_link':
      $block['subject'] = '';
      $block['pages'] = 'categories';
      $link_text = t('Add category');
      $block['content'] = l( $link_text, 'node/add/category');
      break;
    case 'TPA_iframe_map':
      $block['subject'] = '';
      //$block['content'] = "<iframe src='http://localhost/msmap/index.html?config=eurov.js' />";
      $block['content'] = "<iframe src='http://malmoevent.munkeby.se/map/leafsmap/?config=eurov.js&xy=13.0,55.6' />";
      
      break;
  }

  return $block;
}