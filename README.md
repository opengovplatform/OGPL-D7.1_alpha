INSTALLATION:

1- Make sure that your hosting environment meets the following requirements: http://drupal.org/requirements and both git and drush 5.8 (or later) are installed
2- Run: git clone https://github.com/REI-Systems/OGPL-D7.1_alpha.git
3- Set-up the hosting environment for the cloned drupal distribution
4- Run: drush si ogpl7 --sites-subdir=<domain> --db-url=mysql://<username>:<password>@<domain>:<port>/<database> --account-name=<username> --account-mail=<accountemail> --account-pass=<userpassword> --site-mail=<siteemail> --site-name=<sitename>
5- Enable Datagov Content Moderation feature 
6- Enjoy!

