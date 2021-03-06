// <?php
/**
 * @file
 *
 * is an alter plugin for defaultcontent
 *
 * Handles the exporting and importing of og fields
 */
$plugin = array(
  'export_alter weight' => 1001,
);

/**
 * handles the organic grouops transfer of data from node to export
 *
 * change the group_audience to the machine_name that references
 */
function og_export_alter(&$node, &$export) {
  $keys = array(
    'group_group',
    'og_roles_permissions',
  );

  foreach ($keys as $key) {
    if(isset($node->{$key})) {
      $export->{$key} = $node->{$key};
    }
  }

  if (isset($node->group_audience)) {
    $fields = get_group_audience_fields();
    $export->og_audience = array();
    foreach($fields as $field_name => $field) {
      if (isset($node->{$field_name})) {
        foreach ($node->{$field_name} as $lang => $items) {
          foreach ($items as $key => $item) {
            if (($nid = og_load($item['gid'])->etid) && ($machine_name = defaultcontent_get_default($nid))) {
              $export->og_audience[] = $machine_name;
            }
          }
        }
      }
    }
  }
}

/**
* after import handles set the associations
*/
function og_post_import($node) {
  if(isset($node->og_audience)) {
    foreach($node->og_audience as $machine_name) {
      if ($nid = defaultcontent_get_default($machine_name)) {
        $gids = og_get_group_ids('group', array($nid));
        foreach ($gids as $gid) {
          $group = og_get_group('node', $gid);
          $values = array('entity type' => 'node', 'entity' => $node);
          og_group($group->gid, $values);
        }
      }
    }
  }
}

/**
 * helper function to get all group_audience fields
 */
function get_group_audience_fields() {
  $group_audience_fields = array();
  foreach(field_info_fields() as $id=>$field) {
    if ($field['type'] == 'group' && $field['field_name'] == 'group_audience') {
      $group_audience_fields[$id] = $field;
    }
  }
  return $group_audience_fields;
}
