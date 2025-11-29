# Awesome tutorial

https://tuto.grademe.fr/inception/

# Docker Commands

`docker image ls`: list images
`docker ps`: show running containers
`docker ps -a`: show stopped + running containers

`docker exec -it mariadb bash`: run interactive terminal inside mariadb container

`docker exec -it mariadb mariadb -u root -p -h 127.0.0.1`
`docker exec -it mariadb mariadb -u wp_owner -p`

### mariadb volume mapping

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

### mariadb: MariaDB configuration file

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
