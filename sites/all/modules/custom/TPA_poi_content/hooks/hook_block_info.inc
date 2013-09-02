<?php

/**
 * Implementation of hook_block_info().
 */
function TPA_poi_content_block_info() {    
  // Add poi
  $blocks['TPA_add_poi_link'] = array(
    'info' => t('Link to add new poi.'),
  );

  // Add subcategory
  $blocks['TPA_add_subcategory_link'] = array(
    'info' => t('Link to add new subcategory.'),
  );

  // Add category
  $blocks['TPA_add_category_link'] = array(
    'info' => t('Link to add new category.'),
  );

  // Add category
  $blocks['TPA_iframe_map'] = array(
    'info' => t('Malmö stad map'),
  );

  return $blocks;
}