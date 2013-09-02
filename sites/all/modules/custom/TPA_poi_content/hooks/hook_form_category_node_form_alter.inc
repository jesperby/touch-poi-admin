<?php

/**
 * Implementation of hook_form_alter() for category_node_form.
 */
function TPA_poi_content_form_category_node_form_alter(&$form, &$form_state) {
  // Preview
  unset($form['actions']['preview']);

  // Submit
  $form['actions']['submit']['#submit'][] = 'TPA_add_category_submit';
}
