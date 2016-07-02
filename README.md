# Mailchimp subscribe module for drupal 7.

**Main settings**

admin/config/mailchimp_subscribe/main

On this page you can add mailchimp api key and mailchimp list id for new emails.


**How it is work?**

If you want add new user to your mailchimp list use:
```php
<?php $status = mailchimp_add($user_email, $user_name); ?>
```


