#!/bin/bash
set -e

# Initialize database if not present
if [ ! -d "/var/lib/mysql/${MARINA_DB_DATABASE}" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    mysqld --user=mysql --bootstrap << EOF
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS ${MARINA_DB_DATABASE};
CREATE USER IF NOT EXISTS '${MARINA_DB_USER}'@'%' IDENTIFIED BY '${MARINA_DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MARINA_DB_DATABASE}.* TO '${MARINA_DB_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARINA_DB_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF
fi

exec "$@"