<?php

function TPA_malmo_assets_preprocess_views_view(&$vars) {
  if( $vars['display_id'] == 'page' || 
  	  $vars['display_id'] == 'page_1' ) {

  	// Use asset btn design for select input
  	$pattern = 'class=\"form-select\"';
  	$replacement = 'class="btn"';
  	$vars['exposed'] = mb_ereg_replace ( $pattern, $replacement, $vars['exposed'] );

  	// Use asset btn design for input button
  	$pattern = 'class=\"form-submit\"';
  	$replacement = 'class="btn"';
  	$vars['exposed'] = mb_ereg_replace ( $pattern, $replacement, $vars['exposed'] );  	
  }
}