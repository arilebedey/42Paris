FROM debian:bullseye

RUN apt-get update && apt-get install -y --no-install-recommends \
    mariadb-server \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/mysqld \
    && chown -R mysql:mysql /var/run/mysqld \
    && chmod 755 /var/run/mysqld

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/init-db.sh /usr/local/bin/init-db.sh

RUN chmod +x /usr/local/bin/init-db.sh

EXPOSE 3306

ENTRYPOINT ["/usr/local/bin/init-db.sh"]
