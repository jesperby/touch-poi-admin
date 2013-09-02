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
  $handler->display->display_options['title'] = 'Platskategorier';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Välj';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Återställ';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« första';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ föregående';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nästa ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sista »';
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
  /* Fält: Innehåll: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Fält: Innehåll: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  /* Fält: Innehåll: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Sort criterion: Innehåll: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Innehåll: Publicerad */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Platser */
  $handler = $view->new_display('page', 'Platser', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Platser';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Fält: Innehåll: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Fält: Innehåll: Edit link */
  $handler->display->display_options['fields']['edit_node_1']['id'] = 'edit_node_1';
  $handler->display->display_options['fields']['edit_node_1']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node_1']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node_1']['label'] = '';
  /* Fält: Innehåll: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Innehåll: Publicerad */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Innehåll: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poi' => 'poi',
  );
  /* Filter criterion: Innehåll: Platskategori (field_subcategory) */
  $handler->display->display_options['filters']['field_subcategory_target_id']['id'] = 'field_subcategory_target_id';
  $handler->display->display_options['filters']['field_subcategory_target_id']['table'] = 'field_data_field_subcategory';
  $handler->display->display_options['filters']['field_subcategory_target_id']['field'] = 'field_subcategory_target_id';
  $handler->display->display_options['filters']['field_subcategory_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subcategory_target_id']['expose']['operator_id'] = 'field_subcategory_target_id_op';
  $handler->display->display_options['filters']['field_subcategory_target_id']['expose']['operator'] = 'field_subcategory_target_id_op';
  $handler->display->display_options['filters']['field_subcategory_target_id']['expose']['identifier'] = 'field_subcategory_target_id';
  $handler->display->display_options['filters']['field_subcategory_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_subcategory_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    3 => '3',
    1 => 0,
    5 => 0,
  );
  $handler->display->display_options['path'] = 'pois';

  /* Display: Platskategorier */
  $handler = $view->new_display('page', 'Platskategorier', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Fält: Innehåll: Ikon för karta */
  $handler->display->display_options['fields']['field_map_icon']['id'] = 'field_map_icon';
  $handler->display->display_options['fields']['field_map_icon']['table'] = 'field_data_field_map_icon';
  $handler->display->display_options['fields']['field_map_icon']['field'] = 'field_map_icon';
  $handler->display->display_options['fields']['field_map_icon']['label'] = '';
  $handler->display->display_options['fields']['field_map_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_map_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_map_icon']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Fält: Innehåll: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Fält: Innehåll: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Fält: Innehåll: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Innehåll: Publicerad */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Innehåll: Kategori (field_category) */
  $handler->display->display_options['filters']['field_category_target_id']['id'] = 'field_category_target_id';
  $handler->display->display_options['filters']['field_category_target_id']['table'] = 'field_data_field_category';
  $handler->display->display_options['filters']['field_category_target_id']['field'] = 'field_category_target_id';
  $handler->display->display_options['filters']['field_category_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_category_target_id']['expose']['operator_id'] = 'field_category_target_id_op';
  $handler->display->display_options['filters']['field_category_target_id']['expose']['operator'] = 'field_category_target_id_op';
  $handler->display->display_options['filters']['field_category_target_id']['expose']['identifier'] = 'field_category_target_id';
  $handler->display->display_options['filters']['field_category_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_category_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    3 => '3',
    1 => 0,
    5 => 0,
  );
  /* Filter criterion: Innehåll: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'subcategory' => 'subcategory',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Typ';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'subcategories';

  /* Display: Kategorier */
  $handler = $view->new_display('page', 'Kategorier', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Kategorier';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Fält: Innehåll: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Fält: Innehåll: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Fält: Innehåll: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Innehåll: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Innehåll: Publicerad */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Innehåll: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'category' => 'category',
  );
  $handler->display->display_options['path'] = 'categories';
  $translatables['pois'] = array(
    t('Master'),
    t('Platskategorier'),
    t('more'),
    t('Välj'),
    t('Återställ'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« första'),
    t('‹ föregående'),
    t('nästa ›'),
    t('sista »'),
    t('Delete link'),
    t('Edit link'),
    t('Platser'),
    t('Typ'),
    t('Kategorier'),
  );
  $export['pois'] = $view;

  return $export;
}
