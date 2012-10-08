<?php

/**
 * @file
 * Administration callbacks for the og_massadd module
 */

/**
 * Configure module.
 */
function og_massadd_admin_settings() {

  $form['og_massadd_createunknowns'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create unknown users.'),
    '#description' => t('If this is set, users not present in the Drupal user table will be created.'),
    '#default_value' => variable_get('og_massadd_createunknowns', FALSE),
  );

  if (module_exists('content_profile')) {
    $form['og_massadd_profilenode'] = array(
      '#type' => 'textfield',
      '#title' => t('Name of content_profile node type.'),
      '#description' => t('Enter the machine readable name of the content type you want og_massadd to use for content_profile creation, or leave empty for no profile creation.'),
      '#default_value' => variable_get('og_massadd_profilenode', reset(array_keys(content_profile_get_types('names')))),
      '#resizable' => FALSE,
    );

    $form['og_massadd_profilefname'] = array(
      '#type' => 'textfield',
      '#title' => t('Field for user\'s first name.'),
      '#description' => t('Enter the machine readable name of the field that contains the user\'s first name or leave empty.'),
      '#default_value' => variable_get('og_massadd_profilefname', 'firstname'),
      '#resizable' => FALSE,
    );

    $form['og_massadd_profilelname'] = array(
      '#type' => 'textfield',
      '#title' => t('Field for user\'s last name.'),
      '#description' => t('Enter the machine readable name of the field that contains the user\'s last name or leave empty.'),
      '#default_value' => variable_get('og_massadd_profilelname', 'lastname'),
      '#resizable' => FALSE,
    );

  }



  return system_settings_form($form);

}

/**
 * Validate the certify configuration form
 */
function og_massadd_admin_settings_validate($form, $form_state) {
  if (module_exists('content_profile')) {

    $profilenode = $form_state['values']['og_massadd_profilenode'];

    if (strlen($profilenode) && !is_content_profile($profilenode)) {
      form_set_error('og_massadd_profilenode', t('Please choose a profile node (or leave blank).'));
    }

    $fname = $form_state['values']['og_massadd_profilefname'];
    if (strlen($profilenode) && strlen($fname) && !content_fields($fname,$profilenode)) {
      form_set_error('og_massadd_profilefname', t('Please choose a field for the user\'s first name or leave empty.'));
    }

    $lname = $form_state['values']['og_massadd_profilelname'];
    if (strlen($profilenode) && strlen($lname) && !content_fields($lname,$profilenode)) {
      form_set_error('og_massadd_profilelname', t('Please choose a field for the user\'s last name or leave empty.'));
    }

  }

}

  

