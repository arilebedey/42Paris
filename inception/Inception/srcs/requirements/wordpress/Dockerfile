FROM debian:bullseye

RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates php7.4-fpm php7.4-mysql curl tar mariadb-client dumb-init \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html

RUN update-ca-certificates

RUN curl -O https://wordpress.org/latest.tar.gz \
    && tar -xzf latest.tar.gz --strip-components=1 \
    && rm latest.tar.gz \
    && chown -R www-data:www-data /var/www/html

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY tools/setup.sh /usr/local/bin/setup.sh
RUN chmod +x /usr/local/bin/setup.sh

EXPOSE 9000

ENTRYPOINT ["dumb-init", "--", "/usr/local/bin/setup.sh"]
