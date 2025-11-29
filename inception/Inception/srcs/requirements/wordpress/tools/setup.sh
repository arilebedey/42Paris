#!/bin/bash

read_secret_safely() {
    cat "$1" 2>/dev/null || echo ""
}

DB_PASS=$(read_secret_safely "${WORDPRESS_DB_PASSWORD_FILE}")

cd /var/www/html

if [ ! -f wp-config.php ]; then
    echo "Generating wp-config.php ..."
    cp wp-config-sample.php wp-config.php
    sed -i "s/database_name_here/${WORDPRESS_DB_NAME}/" wp-config.php
    sed -i "s/username_here/${WORDPRESS_DB_USER}/" wp-config.php
    sed -i "s/password_here/${DB_PASS}/" wp-config.php
    sed -i "s/localhost/${WORDPRESS_DB_HOST}/" wp-config.php

    WP_KEYS=$(curl -s https://api.wordpress.org/secret-key/1.1/salt/)
    sed -i "/AUTH_KEY/d;/SECURE_AUTH_KEY/d;/LOGGED_IN_KEY/d;/NONCE_KEY/d;/AUTH_SALT/d;/SECURE_AUTH_SALT/d;/LOGGED_IN_SALT/d;/NONCE_SALT/d" wp-config.php
    printf '%s\n' "${WP_KEYS}" >> wp-config.php
fi

chown -R www-data:www-data /var/www/html
exec php-fpm7.4 -F
