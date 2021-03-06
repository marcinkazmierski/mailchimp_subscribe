<?php

/**
 * Callback function.
 */
function _mailchimp_subscribe_lists_form($form, &$form_state)
{
    $form['mailchimp'] = array(
        '#type' => 'fieldset',
        '#title' => t('Mailchimp settings.'),
    );
    $form['mailchimp']['mailchimp_api_key'] = array(
        '#type' => 'textfield',
        '#title' => t('API KEY'),
        '#default_value' => variable_get('mailchimp_api_key'),
    );
    $form['mailchimp']['mailchimp_list_default'] = array(
        '#type' => 'textfield',
        '#title' => t('List ID:'),
        '#default_value' => variable_get('mailchimp_list_default'),
    );
    $form['mailchimp']['description']['#markup'] = t('<p>If you want add new user to your mailchimp list use: <i>') . htmlspecialchars('<?php $status = mailchimp_add($user_email, $user_name); ?>') . '</i></p>';
    $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save'),
    );

    return $form;
}

/**
 * Form submit.
 */
function _mailchimp_subscribe_lists_form_submit($form, &$form_state)
{
    $values = $form_state['values'];
    foreach ($values as $key => $value) {
        if (strpos($key, 'mailchimp') === 0) {
            variable_set($key, $value);
        }
    }
    drupal_set_message('The configuration options have been saved.');
}
