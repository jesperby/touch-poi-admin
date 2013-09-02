<?php

function TPA_malmo_assets_preprocess_block(&$variables) {
  if( $variables['block_html_id'] == 'block-tpa-poi-content-tpa-add-subcategory-link' ) {
    
    $variables['content'] = theme(  'TPA_asset_button_link', array(
                                      'url' => 'node/add/subcategory', 
                                      'text' => t('Add subcategory') ) );
  } else if ( $variables['block_html_id'] == 'block-tpa-poi-content-tpa-add-poi-link' ) {
    $variables['content'] = theme(  'TPA_asset_button_link', array(
                                      'url' => 'node/add/poi', 
                                      'text' => t('Add poi') ) );
  } else if ( $variables['block_html_id'] == 'block-tpa-poi-content-tpa-add-category-link' ) {
    $variables['content'] = theme(  'TPA_asset_button_link', array(
                                      'url' => 'node/add/category', 
                                      'text' => t('Add category') ) );
  }
}