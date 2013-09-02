<?php

/**
 * Implementation of hook_form_alter() for subcategory_node_form.
 */
function TPA_poi_content_form_subcategory_node_form_alter(&$form, &$form_state) {
  // Preview
  unset($form['actions']['preview']);

  // Submit
  $form['actions']['submit']['#submit'][] = 'TPA_add_subcategory_submit';
}
