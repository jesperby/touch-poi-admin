<?php
/**
 * @file
 * poi_and_categories_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function poi_and_categories_content_types_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_autumn_dates|node|poi|form';
  $field_group->group_name = 'group_autumn_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'poi';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Höst - Datum',
    'weight' => '9',
    'children' => array(
      0 => 'field_autumn_end_month',
      1 => 'field_autumn_start_month',
      2 => 'field_autumn_start_day',
      3 => 'field_autumn_end_day',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_autumn_dates|node|poi|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_autumn_times|node|poi|form';
  $field_group->group_name = 'group_autumn_times';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'poi';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Höst - Tider',
    'weight' => '10',
    'children' => array(
      0 => 'field_autumn_start_hour',
      1 => 'field_autumn_end_hour',
      2 => 'field_autumn_start_minute',
      3 => 'field_autumn_end_minute',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_autumn_times|node|poi|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_spring_dates|node|poi|form';
  $field_group->group_name = 'group_spring_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'poi';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vår - Datum',
    'weight' => '7',
    'children' => array(
      0 => 'field_spring_start_month',
      1 => 'field_spring_end_month',
      2 => 'field_spring_end_day',
      3 => 'field_spring_start_day',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-spring-dates field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_spring_dates|node|poi|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_spring_times|node|poi|form';
  $field_group->group_name = 'group_spring_times';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'poi';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vår - Tider',
    'weight' => '8',
    'children' => array(
      0 => 'field_spring_start_hour',
      1 => 'field_spring_end_hour',
      2 => 'field_spring_start_minute',
      3 => 'field_spring_end_minute',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_spring_times|node|poi|form'] = $field_group;

  return $export;
}
