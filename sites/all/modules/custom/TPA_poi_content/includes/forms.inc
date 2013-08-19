<?php

/* 
 * Form helper functions
 */


/*
 * Add poi submit function
 */
function TPA_add_poi_submit($form, &$form_state) {
  unset($form_state['rebuild']); 
  $form_state['redirect'] = 'pois';
}


/*
 * Add subcategory submit function
 */
function TPA_add_subcategory_submit($form, &$form_state) {
  unset($form_state['rebuild']); 
  $form_state['redirect'] = 'subcategories';
}


/*
 * Add category submit function
 */
function TPA_add_category_submit($form, &$form_state) {
  unset($form_state['rebuild']); 
  $form_state['redirect'] = 'categories';
}

