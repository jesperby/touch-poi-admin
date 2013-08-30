<?php
/**
 * @file
 * malmo_assets_theme.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function malmo_assets_theme_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  return $permissions;
}
