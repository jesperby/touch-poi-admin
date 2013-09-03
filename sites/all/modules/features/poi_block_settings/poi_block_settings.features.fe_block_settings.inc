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
      'TPA_malmo_assets' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'TPA_malmo_assets',
        'weight' => 0,
      ),
      'bartik' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -9,
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
      'TPA_malmo_assets' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'TPA_malmo_assets',
        'weight' => 0,
      ),
      'bartik' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -8,
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
      'TPA_malmo_assets' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'TPA_malmo_assets',
        'weight' => 0,
      ),
      'bartik' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -7,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['TPA_poi_content-TPA_iframe_map'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'TPA_iframe_map',
    'module' => 'TPA_poi_content',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'TPA_malmo_assets' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'TPA_malmo_assets',
        'weight' => 0,
      ),
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['TPA_theming-TPA_footer_nav'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'TPA_footer_nav',
    'module' => 'TPA_theming',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'TPA_malmo_assets' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'TPA_malmo_assets',
        'weight' => 0,
      ),
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'TPA_malmo_assets' => array(
        'region' => 'assets_service_title',
        'status' => 1,
        'theme' => 'TPA_malmo_assets',
        'weight' => 0,
      ),
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => -11,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'TPA_malmo_assets' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'TPA_malmo_assets',
        'weight' => 0,
      ),
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
