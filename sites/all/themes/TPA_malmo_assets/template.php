<?php
/**
 * @file
 *   Theme implementation functions for Malmö Stad.
 */

/**
 * Various
 */
require_once './' . drupal_get_path('theme', 'TPA_malmo_assets') . '/includes/config.inc';
require_once './' . drupal_get_path('theme', 'TPA_malmo_assets') . '/includes/theme.inc';

/**
 * Hooks
 */

// Hook preprocess_html
require_once './' . drupal_get_path('theme', 'TPA_malmo_assets') . '/hooks/hook_preprocess_html.inc';

// Hook preprocess_region
require_once './' . drupal_get_path('theme', 'TPA_malmo_assets') . '/hooks/hook_preprocess_region.inc';

// Hook preprocess_block
require_once './' . drupal_get_path('theme', 'TPA_malmo_assets') . '/hooks/hook_preprocess_block.inc';

// Hook preprocess_block
require_once './' . drupal_get_path('theme', 'TPA_malmo_assets') . '/hooks/hook_preprocess_views_view.inc';

// Hook menu_link
require_once './' . drupal_get_path('theme', 'TPA_malmo_assets') . '/hooks/hook_menu_link.inc';

// Hook preprocess_page
require_once './' . drupal_get_path('theme', 'TPA_malmo_assets') . '/hooks/hook_preprocess_page.inc';

// Hook preprocess_maintenance_page
require_once './' . drupal_get_path('theme', 'TPA_malmo_assets') . '/hooks/hook_preprocess_maintenance_page.inc';

// Hook form_element
//require_once './' . drupal_get_path('theme', 'TPA_malmo_assets') . '/hooks/hook_form_element.inc';

// Hook form
//require_once './' . drupal_get_path('theme', 'TPA_malmo_assets') . '/hooks/hook_form.inc';

// Hook preprocess_category_node_form
//require_once './' . drupal_get_path('theme', 'TPA_malmo_assets') . '/hooks/hook_preprocess_category_node_form.inc';
