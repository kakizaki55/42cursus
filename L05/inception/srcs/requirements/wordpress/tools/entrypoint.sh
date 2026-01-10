#!/bin/bash
set -e

# Wait for MariaDB to be ready
sleep 5

cd /var/www/html

# Download WordPress if not present
if [ ! -f wp-config.php ]; then
    wp core download --allow-root

    wp config create \
        --dbname="${MYSQL_DATABASE}" \
        --dbuser="${MYSQL_USER}" \
        --dbpass="${MYSQL_PASSWORD}" \
        --dbhost="${MYSQL_HOSTNAME}" \
        --allow-root

    wp core install \
        --url="${DOMAIN_NAME}" \
        --title="Inception" \
        --admin_user="superuser" \
        --admin_password="super1234" \
        --admin_email="superuser@example.com" \
        --allow-root

    wp user create editor editor@example.com \
        --role=editor \
        --user_pass="editor1234" \
        --allow-root

    chown -R www-data:www-data /var/www/html
fi

# Configure php-fpm to listen on port 9000
sed -i 's|listen = /run/php/php7.4-fpm.sock|listen = 9000|g' /etc/php/7.4/fpm/pool.d/www.conf

exec "$@"