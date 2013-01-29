<?php
/**
 * @file
 * data_gov_communities_configuration.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function data_gov_communities_configuration_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:communities
  $menu_links['main-menu:communities'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'communities',
    'router_path' => 'communities',
    'link_title' => 'Communities',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '22',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Communities');


  return $menu_links;
}