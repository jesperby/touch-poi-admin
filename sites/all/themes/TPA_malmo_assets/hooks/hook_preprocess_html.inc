<?php

/**
 * Preprocesses the wrapping HTML.
 *
 * @param array &$variables
 *   Template variables.
 */
function TPA_malmo_assets_preprocess_html(&$vars) {
  // Assets config
  require_once './' . drupal_get_path('theme', 'TPA_malmo_assets') . '/config/assets-config.inc';
  
  // Determine asset url based on environment
  $assets_url = TPA_malmo_assets_localenv( $assets_config ) && $assets_config['testenv_assets']=='local' ? "//" . $assets_config['assetsurl_local'] : "//" . $assets_config['assetsurl_prod'];
  
  // Include assets-3.0 resources as specified in asset documentation

  // malmo.css
  $asset_malmo_css = array(
    '#type' => 'html_tag',
    '#tag' => 'link',
    '#attributes' => array(
      'href' =>  $assets_url . '/malmo.css',
      'rel' => 'stylesheet',
      'type' => 'text/css')
  );
  drupal_add_html_head($asset_malmo_css, 'asset_malmo_css');
 
  // html5shiv-printshiv.js
  $html5shiv_printshiv_js = array(
    '#tag' => 'script',
    '#attributes' => array(
      'src' => $assets_url . 'html5shiv-printshiv.js', 
    ),
    '#prefix' => '<!--[if lte IE 8]>',
    '#suffix' => '</script><![endif]-->',
  );
  drupal_add_html_head($html5shiv_printshiv_js, 'html5shiv_printshiv_js');

  // ie9.css
  $ie9_css = array(
    '#tag' => 'script',
    '#attributes' => array(
      'src' => $assets_url . 'legacy/ie9.css', 
    ),
    '#prefix' => '<!--[if lte IE 8]>',
    '#suffix' => '</script><![endif]-->',
  );
  drupal_add_html_head($ie9_css, 'ie9_css');

  // ie7.css
  $ie7_css = array(
    '#tag' => 'script',
    '#attributes' => array(
      'src' => $assets_url . 'legacy/ie7.css', 
    ),
    '#prefix' => '<!--[if lte IE 8]>',
    '#suffix' => '</script><![endif]-->',
  );
  drupal_add_html_head($ie7_css, 'ie7_css');

  // Add malmo.js at bottom of page
  $data = $assets_url . "/malmo.js";
  $options = array( "type" => "external", "scope" => "footer" );
  drupal_add_js( $data, $options );

  // For pages containing forms, an additional class is needed in the body tag
  if( arg(0) == 'user' && arg(1) == 'login' ||
      arg(0) == 'node' && arg(1) == 'add' && arg(2) == 'poi' ||
      arg(0) == 'node' && arg(1) == 'add' && arg(2) == 'subcategory' ||
      arg(0) == 'node' && arg(1) == 'add' && arg(2) == 'category' ||
      arg(0) == 'node' && arg(2) == 'edit' && mb_substr( $_GET['destination'], 0, 4) == 'pois' ||
      arg(0) == 'node' && arg(2) == 'edit' && mb_substr( $_GET['destination'], 0, 13) == 'subcategories' ||
      arg(0) == 'node' && arg(2) == 'edit' && mb_substr( $_GET['destination'], 0, 10) == 'categories' ) {
    $vars['classes_array'][] = 'malmo-form';
  }
}