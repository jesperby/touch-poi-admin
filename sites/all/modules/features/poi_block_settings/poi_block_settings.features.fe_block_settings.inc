<?php
/**
 * @file
 * poi_block_settings.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function poi_block_settings_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['TPA_poi_content-TPA_add_category_link'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'TPA_add_category_link',
    'module' => 'TPA_poi_content',
    'node_types' => array(),
    'pages' => 'categories',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'touch_poi' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'touch_poi',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['TPA_poi_content-TPA_add_poi_link'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'TPA_add_poi_link',
    'module' => 'TPA_poi_content',
    'node_types' => array(),
    'pages' => 'pois',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'touch_poi' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'touch_poi',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['TPA_poi_content-TPA_add_subcategory_link'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'TPA_add_subcategory_link',
    'module' => 'TPA_poi_content',
    'node_types' => array(),
    'pages' => 'subcategories',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'touch_poi' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'touch_poi',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
