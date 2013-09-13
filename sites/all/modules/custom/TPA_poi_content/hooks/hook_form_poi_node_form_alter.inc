<?php

/**
 * Implementation of hook_form_alter() for poi_node_form.
 */
function TPA_poi_content_form_poi_node_form_alter(&$form, &$form_state) {
  // Include js config
  drupal_add_js(  drupal_get_path('module', 'TPA_poi_content') . '/js/config.js', 
                  array(  'type' => 'file', 
                          'group' => JS_DEFAULT ) );

  // Include proj4js for coordinate transformation
  drupal_add_js(  base_path() . 'malmostad_map/lib/proj4js/lib/proj4js-compressed.js', 
                  array(  'type' => 'file', 
                          'group' => JS_DEFAULT ) );  

  // Include the JQuery ui autocomplete for the address autocomplete 
  drupal_add_library('system', 'ui.autocomplete');
  
  // Change max nr of chars for latitude and longitude fields
  $form['field_latitude']['und'][0]['value']['#maxlength'] = 100;
  $form['field_longitude']['und'][0]['value']['#maxlength'] = 100;

  // Add map handling
  drupal_add_js(  drupal_get_path('module', 'TPA_poi_content') . '/js/map.js', 
                  array(  'type' => 'file', 
                          'group' => JS_DEFAULT ) );
  
  // Display poi marker on map if coords exist
  if( isset( $form['field_geolocation']['und'][0]['#entity']->field_geolocation['und'][0]['lng'] ) &&
      isset( $form['field_geolocation']['und'][0]['#entity']->field_geolocation['und'][0]['lat'] ) ) {
    $lat = $form['field_geolocation']['und'][0]['#entity']->field_geolocation['und'][0]['lat'];
    $lon = $form['field_geolocation']['und'][0]['#entity']->field_geolocation['und'][0]['lng'];
    $coord_parameter = '&xy=' . $lon . "," . $lat;
  } else {
    $coord_parameter = '';
  }

  // Add the map
  $map_url = base_path() . "malmostad_map/index.html?config=eurov.js";
  $form['malmostad_map'] = array(
    "#markup" => "  <div id='map_wrapper'>
                      <iframe  src='$map_url$coord_parameter'
                                onload='Drupal.behaviors.mapHandler.map_loaded()' 
                                id='map_iframe' seamless>
                       </iframe>
                    </div>
                  ",
    "#weight" => 25,
  );

  // Disable / enable input fields based on chosen subcategory
  drupal_add_js(  drupal_get_path('module', 'TPA_poi_content') . '/js/disable_add_poi_fields.js', 
                  array(  'type' => 'file', 
                          'group' => JS_DEFAULT ) );  
  // Remove preview button
  unset($form['actions']['preview']);

  // Submit
  $form['actions']['submit']['#submit'][] = 'TPA_add_poi_submit';
}