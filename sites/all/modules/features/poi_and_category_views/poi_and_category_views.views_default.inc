<?php
/**
 * @file
 * poi_and_category_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function poi_and_category_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'pois';
  $view->description = 'View for lists of all poi, subcategories and categories.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Pois and categories';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Subcategories';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'delete_node' => 'delete_node',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Pois */
  $handler = $view->new_display('page', 'Pois', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Pois';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poi' => 'poi',
  );
  /* Filter criterion: Content: Subcategory (field_subcategory) */
  $handler->display->display_options['filters']['field_subcategory_target_id']['id'] = 'field_subcategory_target_id';
  $handler->display->display_options['filters']['field_subcategory_target_id']['table'] = 'field_data_field_subcategory';
  $handler->display->display_options['filters']['field_subcategory_target_id']['field'] = 'field_subcategory_target_id';
  $handler->display->display_options['filters']['field_subcategory_target_id']['value'] = array(
    'all' => 'all',
    1 => '1',
    2 => '2',
    3 => '3',
    8 => '8',
    9 => '9',
    10 => '10',
  );
  $handler->display->display_options['filters']['field_subcategory_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subcategory_target_id']['expose']['operator_id'] = 'field_subcategory_target_id_op';
  $handler->display->display_options['filters']['field_subcategory_target_id']['expose']['label'] = 'Subcategory (field_subcategory)';
  $handler->display->display_options['filters']['field_subcategory_target_id']['expose']['operator'] = 'field_subcategory_target_id_op';
  $handler->display->display_options['filters']['field_subcategory_target_id']['expose']['identifier'] = 'field_subcategory_target_id';
  $handler->display->display_options['filters']['field_subcategory_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'pois';

  /* Display: Subcategories */
  $handler = $view->new_display('page', 'Subcategories', 'page_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Category (field_category) */
  $handler->display->display_options['filters']['field_category_target_id']['id'] = 'field_category_target_id';
  $handler->display->display_options['filters']['field_category_target_id']['table'] = 'field_data_field_category';
  $handler->display->display_options['filters']['field_category_target_id']['field'] = 'field_category_target_id';
  $handler->display->display_options['filters']['field_category_target_id']['value'] = array(
    'all' => 'all',
    5 => '5',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['filters']['field_category_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_category_target_id']['expose']['operator_id'] = 'field_category_target_id_op';
  $handler->display->display_options['filters']['field_category_target_id']['expose']['label'] = 'Category (field_category)';
  $handler->display->display_options['filters']['field_category_target_id']['expose']['operator'] = 'field_category_target_id_op';
  $handler->display->display_options['filters']['field_category_target_id']['expose']['identifier'] = 'field_category_target_id';
  $handler->display->display_options['filters']['field_category_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'subcategory' => 'subcategory',
  );
  $handler->display->display_options['path'] = 'subcategories';

  /* Display: Categories */
  $handler = $view->new_display('page', 'Categories', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Categories';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'category' => 'category',
  );
  $handler->display->display_options['path'] = 'categories';
  $export['pois'] = $view;

  return $export;
}
