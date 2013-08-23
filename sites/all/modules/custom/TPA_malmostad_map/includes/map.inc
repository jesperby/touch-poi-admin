<?php
	$map_dir_path = drupal_get_path('module', 'TPA_poi_content') . '/map/';

	drupal_add_css( 'http://cdn.leafletjs.com/leaflet-0.5/leaflet.css', array('type' => 'external'));
	drupal_add_css( $map_dir_path . 'js/controls/leaflet-locatecontrol-gh-pages/src/L.Control.Locate.css' );
	
	// lt IE 9
	drupal_add_css( 'http://cdn.leafletjs.com/leaflet-0.5.1/leaflet.ie.css', 
									array(
										'type' => 'external',
								    'group' => CSS_DEFAULT,
								    'browsers' => array(
								      'IE' => 'lt IE 9',
								      '!IE' => FALSE
								      )
								  ));
	drupal_add_css( $map_dir_path . 'js/controls/leaflet-locatecontrol-gh-pages/src/L.Control.Locate.ie.css', 
									array(
										'type' => 'internal',
								    'group' => CSS_DEFAULT,
								    'browsers' => array(
								      'IE' => 'lt IE 9',
								      '!IE' => FALSE
								      )
								  ));
	
	drupal_add_css( $map_dir_path . 'lib/jquery.mobile-1.3.0/jquery.mobile-1.3.0.min.css' );
	drupal_add_css( $map_dir_path . 'lib/smapdialog/smapdialog.css' );
	drupal_add_css( $map_dir_path . 'lib/add-to-homescreen/style/add2home.css' );

	drupal_add_css( $map_dir_path . 'css/style.css' );
	drupal_add_css( $map_dir_path . 'js/controls/leaflet-eurovision/eurovision.css' );
	drupal_add_css( $map_dir_path . 'js/controls/leaflet-search/search.css' );
	drupal_add_css( $map_dir_path . 'js/controls/leaflet-choose-region/chooseregion.css' );
	drupal_add_css( $map_dir_path . 'js/controls/leaflet-eurovision-view/eurovisionView.css' );

	// lt IE 8
	drupal_add_css( 'http://cdn.leafletjs.com/leaflet-0.5/leaflet.ie.css', 
									array(
										'type' => 'external',
								    'group' => CSS_DEFAULT,
								    'browsers' => array(
								      'IE' => 'lt IE 8',
								      '!IE' => FALSE
								      )
								  ));

drupal_add_js(  'http://cdn.leafletjs.com/leaflet-0.5/leaflet.js', array( 	'type' => 'external' ) );
drupal_add_js(  $map_dir_path . 'js/controls/leaflet-locatecontrol-gh-pages/src/L.Control.Locate.js' );
drupal_add_js(  $map_dir_path . 'js/utils.js' );
drupal_add_js(  $map_dir_path . 'js/controls/leaflet-eurovision/Eurovision.js' );
drupal_add_js(  $map_dir_path . 'js/controls/leaflet-eurovision-view/eurovisionView.js' );
drupal_add_js(  $map_dir_path . 'js/controls/leaflet-search/Search.js' );
drupal_add_js(  $map_dir_path . 'js/controls/leaflet-choose-region/ChooseRegion.js' );

drupal_add_js(  $map_dir_path . 'lib/proj4js/lib/proj4js-compressed.js' );
drupal_add_js(  $map_dir_path . 'lib/jquery.mobile-1.3.0/jquery.mobile-1.3.0.min.js' );
drupal_add_js(  $map_dir_path . 'lib/smapdialog/smapdialog.js' );
drupal_add_js(  $map_dir_path . 'lib/overthrow.js' );

drupal_add_js(  $map_dir_path . 'js/LS.js' );
drupal_add_js(  $map_dir_path . 'js/Main.js' );

//<script src="//ajax.googleapis.com/ajax/libs/jquery/1.8.3/jquery.min.js"></script>
