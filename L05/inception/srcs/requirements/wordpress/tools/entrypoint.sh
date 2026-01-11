#!/bin/bash
set -e

# Wait for MariaDB to be ready
sleep 5

cd /var/www/html

# Download WordPress if not present
if [ ! -f wp-config.php ]; then
    wp core download --allow-root

    wp config create \
        --dbname="${MARINA_DB_DATABASE}" \
        --dbuser="${MARINA_DB_USER}" \
        --dbpass="${MARINA_DB_PASSWORD}" \
        --dbhost="${MARINA_DB_HOSTNAME}" \
        --allow-root

    wp core install \
        --url="${DOMAIN_NAME}" \
        --title="Inception" \
        --admin_user="${WP_ADMIN}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --allow-root

    wp user create "${WP_USER}" "${WP_USER_EMAIL}" \
        --role=editor \
        --user_pass="${WP_USER_PASSWORD}" \
        --allow-root

    chown -R www-data:www-data /var/www/html
fi

# Configure php-fpm to listen on port 9000
sed -i 's|listen = /run/php/php7.4-fpm.sock|listen = 9000|g' /etc/php/7.4/fpm/pool.d/www.conf

exec "$@"