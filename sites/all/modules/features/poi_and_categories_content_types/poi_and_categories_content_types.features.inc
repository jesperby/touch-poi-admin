<?php
/**
 * @file
 * poi_and_categories_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function poi_and_categories_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function poi_and_categories_content_types_node_info() {
  $items = array(
    'category' => array(
      'name' => t('Kategori'),
      'base' => 'node_content',
      'description' => t('Poi categories, such as Nature, Health etc.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'poi' => array(
      'name' => t('Plats'),
      'base' => 'node_content',
      'description' => t('Content type to store points of interest, libraries, restaurants etc, and their meta-data.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'subcategory' => array(
      'name' => t('platskategori'),
      'base' => 'node_content',
      'description' => t('Poi subcategories, such as library, restaurant etc'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
