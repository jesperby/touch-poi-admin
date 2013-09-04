<?php

function TPA_malmo_assets_form($variables) {
  $element = $variables['element'];

  if( $element['#id'] == 'poi-node-form' ) {
  } else if ( $element['#id'] == 'category-node-form' ) {
  	// Change class to assets form-horizontal
  	unset( $variables['element']['#attributes']['class'] );
  	_form_set_class( $variables['element'], array('form-horizontal') );


  }
  
  return theme_form($variables);
}