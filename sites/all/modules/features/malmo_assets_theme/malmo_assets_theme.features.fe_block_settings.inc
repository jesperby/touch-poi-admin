<?php
/**
 * @file
 * malmo_assets_theme.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function malmo_assets_theme_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

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
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
