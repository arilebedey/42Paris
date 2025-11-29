#!/bin/bash

read_secret() {
    cat "/run/secrets/$1" 2>/dev/null || echo ""
}

DB_ROOT_PASS=$(read_secret db_root_password)
DB_USER_PASS=$(read_secret db_password)

if [ -z "$DB_ROOT_PASS" ] || [ -z "$DB_USER_PASS" ]; then
    echo "Error: Missing required secrets."
    exit 1
fi

if [ ! -d "/var/lib/mysql/$MYSQL_DATABASE" ]; then
    echo "Initializing MariaDB data directory..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    mysqld --user=mysql --bootstrap << EOF
FLUSH PRIVILEGES;

ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASS}';

CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;

CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'172.18.%' IDENTIFIED BY '${DB_USER_PASS}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'172.18.%';

CREATE USER IF NOT EXISTS '${MYSQL_SECOND_USER}'@'172.18.%' IDENTIFIED BY '${DB_USER_PASS}';
GRANT SELECT, INSERT, UPDATE ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_SECOND_USER}'@'172.18.%';

FLUSH PRIVILEGES;
EOF

    echo "Database initialized with users: root, ${MYSQL_USER}, ${MYSQL_SECOND_USER}"
else
    echo "Database already exists. Skipping initialization."
fi

exec mysqld --user=mysql
