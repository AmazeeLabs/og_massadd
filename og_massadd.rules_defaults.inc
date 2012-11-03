
<?php

/**
 * Implements hook_default_rules_configuration().
 */
function og_massadd_default_rules_configuration() {
	$items['rules_og_massadd'] = entity_import('rules_config', '{ "rules_add_og_membership" : {
	    "LABEL" : "add_og_membership",
	    "PLUGIN" : "action set",
	    "REQUIRES" : [ "og", "rules" ],
	    "USES VARIABLES" : { "user" : { "label" : "user", "type" : "user" } },
	    "ACTION SET" : [
	      { "og_group_content_add" : { "entity" : [ "user" ], "group" : [ "site:og-context--node" ] } },
	      { "drupal_message" : { "message" : "User [user:name] added to group" } }
	    ]
	  }
	}');

	return $items;
}