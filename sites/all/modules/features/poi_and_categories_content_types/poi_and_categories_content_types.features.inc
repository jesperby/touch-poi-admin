<?php
/**
 * @file
 * poi_and_categories_content_types.features.inc
 */

/**
 * Implements hook_node_info().
 */
function poi_and_categories_content_types_node_info() {
  $items = array(
    'category' => array(
      'name' => t('Category'),
      'base' => 'node_content',
      'description' => t('Poi categories, such as Nature, Health etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'poi' => array(
      'name' => t('Poi'),
      'base' => 'node_content',
      'description' => t('Content type to store points of interest, libraries, restaurants etc, and their meta-data.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'subcategory' => array(
      'name' => t('Subcategory'),
      'base' => 'node_content',
      'description' => t('Poi subcategories, such as library, restaurant etc'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
