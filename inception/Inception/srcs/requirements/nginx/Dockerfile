FROM debian:bullseye

RUN apt-get update && apt-get install -y --no-install-recommends \
    nginx openssl dumb-init && rm -rf /var/lib/apt/lists/*

COPY conf/nginx.conf /etc/nginx/conf.d/default.conf
COPY tools/setup_tls.sh /usr/local/bin/setup_tls.sh
RUN chmod +x /usr/local/bin/setup_tls.sh

EXPOSE 443

ENTRYPOINT ["dumb-init", "--", "/usr/local/bin/setup_tls.sh"]
