# Awesome tutorial

https://tuto.grademe.fr/inception/

# Useful Commands

### Docker Commands

`docker image ls`: list images
`docker ps`: show running containers
`docker ps -a`: show stopped + running containers

`docker exec -it mariadb bash`: run interactive terminal inside mariadb container
`docker stats dev_postgres`: realtime usage/stats
`docker volume inspect foundation_dev-db-data`: show volume hash + fs mountpoint

### `mariadb` Commands

`docker exec -it mariadb mariadb -u root -p wordpress -h 127.0.0.1`
`docker exec -it mariadb mariadb -u wp_owner -p`

### SQL Commands

`SHOW TABLES;`
`SELECT user, host FROM mysql.user;`
`SELECT ID, user_login, user_pass FROM wp_users;`
`docker exec -it mariadb mariadb -u root -p123 -h 127.0.0.1 wordpress -e "SHOW TABLES;"`
`docker exec -it mariadb mariadb -u root -p123 -h 127.0.0.1 wordpress -e "SELECT ID, user_login, user_pass FROM wp_users;"`

# MariaDB

## mariadb: docker-compose

### mariadb: volume mapping

```yml
volumes:
  mariadb_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: ${DATA_PATH}/mariadb
```

`driver: local`: tells we will use the local host FS
`type: none`: tells docker to not create a special FS like nfs or tmpfs
`o: bind`: directly bind host path to container path

## mariadb: MariaDB configuration file

```50-server.cnf
[mysqld]
datadir = /var/lib/mysql
socket  = /var/run/mysqld/mysqld.sock
bind-address = 0.0.0.0
port = 3306
user = mysql
skip-networking = false
```

`bind-address = 0.0.0.0`: listen on all available network interfaces (docker network)

#### user = mysql

Historically, MySQL’s data files were owned and managed by the system user mysql, for compatibility reasons, it was kept that way.

When MariaDB was created, it kept:

- the binary names (e.g. mysqld, mysql_install_db, mysqladmin);
- the data directory (/var/lib/mysql);
- and the system service account (mysql).

## mariadb: Dockerfile details

`EXPOSE 3306`: just metadata to know which port we use (not essential)

### socket file location directory

RUN mkdir -p /var/run/mysqld \
 && chown -R mysql:mysql /var/run/mysqld \
 && chmod 755 /var/run/mysqld

`/var/run/mysqld`: transient files dir while MariaDB is running

## mariadb: init-db.sh

### Server lifecycle commands

`mysql_install_db --user=mysql --datadir=/var/lib/mysql`: install db at the location (mapped to local host's FS)

`mysqld --user=mysql --bootstrap << EOF`: allows SQL command input for configuration

`exec mysqld --user=mysql`: replaces the shell script's process (PID 1) of the container, no restore signal handling graceful start/stop of container

#### SQL syntax

Single quotes are for string literals (usernames, hosts, passwords).  
Backticks are for identifiers (database or table names) to handle special characters or reserved words.

# Wordpress (wp)

## wp: Dockerfile details

`php-fpm` is the runtime that execute PHP code for web requests and returns HTML. It listens on a socket or TCP port (port 9000).

`dumb-init` is a tiny process supervisor used as the PID 1 process inside containers.

`WORKDIR /var/www/html` is often the default folder for the document root for the web content

`www-data` is a dedicated system user and group created by default on most Unix‑like systems when the web server (e.g., NGINX or Apache) or PHP‑FPM is installed. It owns or runs web processes for isolation and safety. It typically owns your web files (/var/www/html) so those processes can read/write as needed.

## WP: php-fmp conf file - www.conf

https://www.atatus.com/blog/php-fpm-performance-optimization/#what-is-php-fpm

```
listen = 9000
user = www-data
group = www-data
```

Defines the port where php-fpm will listen

```
pm = ondemand
pm.max_requests = 2000
pm.max_children = 5
pm.process_idle_timeout = 10s
request_terminate_timeout = 5s
```

`clear_env = no`: don't clean env so WP can see

Is php-fpm's process management configuration. `pm` can be attributed: `dynamic`, `ondemand` or `static`.

`pm.max_children` = (Total PHP RAM) / (Memory per PHP process)

## WP: setup.sh

```
cd /var/www/html
cp wp-config-sample.php wp-config.php
...
sed -i "s/username_here/${WORDPRESS_DB_USER}/" wp-config.php
...

WP_KEYS=$(curl -s https://api.wordpress.org/secret-key/1.1/salt/)
...
printf '%s\n' "${WP_KEYS}" >> wp-config.php
```

Writing hashes and env vars to `/var/www/html/wp-config.php`

`curl -s https://api.wordpress.org/secret-key/1.1/salt/`: the WordPress secret key (salt) generator.

Essentially, they make logins and sessions unpredictable and unique for every installation.

They ensure that even if someone somehow gets your DB or cookies, they can’t easily fake or reuse login tokens

`exec php-fpm7.4 -F`

That makes PHP‑FPM run as PID 1 inside the container.

# nginx

Nginx examines the request using its configuration (e.g. /etc/nginx/conf.d/default.conf) and says:

When nginx encounters a .php file, it forwards the request to that port or socket.

## TLS

Makes sure that:

- Others can’t read or alter the data traveling over the network.
- The browser can verify the server’s identity (via a certificate).
- Both sides agree on encryption algorithms before exchanging data.

TLS uses asymmetric cryptography. Data encrypted with the private key can be verified with the public certificate. Just like `ssh`.

### `openssl` generates the key pair

```
/etc/nginx/ssl/server.key
/etc/nginx/ssl/server.crt
```

### Self-signed certificates

Normally, a browser only trusts certificates signed by a Certificate Authority (CA) (like Let’s Encrypt).
Here, in a learning environment and a VM, you can’t use public DNS or a trusted CA, so we use our own.

`openssl req -x509`: creates a self-signed certificate.

### `nginx.conf`

Both TLSv1.2 and TLSv1.3 require strong ciphers, thus we write

`ssl_ciphers HIGH:!aNULL:!MD5;`:

- algorithms used are high security (>128-bit encryption)
- exclude anonymouse insecure cypher (allow MITM attacks)
- MD5, being cryptographically broken, must never be used for secure data integrity
