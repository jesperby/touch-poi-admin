<?php

function TPA_malmo_assets_preprocess_category_node_form(&$variables) {   
	$form = $variables['form'];
	$variables['title_string'] = drupal_render( $form['title']['#title'] );
	$form['title']['#title'] = '';
	$variables['title_input'] = drupal_render( $form['title'] );
	hide( $form['title'] );
} 