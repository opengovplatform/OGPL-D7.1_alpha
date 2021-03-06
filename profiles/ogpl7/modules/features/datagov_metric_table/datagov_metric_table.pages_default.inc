<?php
/**
 * @file
 * datagov_metric_table.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function datagov_metric_table_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'metrics_page';
  $page->task = 'page';
  $page->admin_title = 'Metrics Page';
  $page->admin_description = '';
  $page->path = 'metrics';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Metrics',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_metrics_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'metrics_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Metrics',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'datagov_onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Metrics';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>This report is also available for download in the following formats: <a href="/metric/federal-agency-participation.csv">CSV</a> | <a href="/metric/federal-agency-participation.xls">EXCEL</a></p>

<?php

$sql = "
SELECT 
  MAX(field_metric_sync_timestamp_value) 
FROM
  {field_data_field_metric_sync_timestamp} f
JOIN
  {node} n
ON
  f.entity_id = n.nid
WHERE
  n.status = 1
";

$result = db_query($sql)->fetchCol();

if (!empty($result) && !empty($result[0])) {
 // Convert to the date string.
 $count_last_update = format_date($result[0], $type = \'custom\', $format = \'m/d/Y g:i A\', $timezone = \'America/New_York\');

 // Echo out.
 echo "<p><em>Data last updated on $count_last_update.</em></p>";
}

?>

<?php
//total agency subagency calculation
$view=views_get_view(\'new_metric_table\');
$view->set_display(\'metric_table_agency_count_pane\');
$view->set_items_per_page(0);
$view->execute();
$agency = sizeof($view->result);

?>

<div id="open-data-sites-boxes" class="clear agencies"><div class="open-data-sites-box"><div class="region">Agencies and Subagencies</div><div class="numbers"><?php echo $agency . " "; ?></div></div></div><div class="clear">&nbsp;</div>',
      'format' => 'php_code',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['middle'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'new_metric_table-metric_table_federal_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['middle'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'new_metric_table-metric_table_other_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['middle'][2] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'new_metric_table-metric_table_summary_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['middle'][3] = 'new-4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['metrics_page'] = $page;

  return $pages;

}
