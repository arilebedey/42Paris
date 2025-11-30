#!/bin/bash

CERT_DIR=/etc/nginx/ssl
mkdir -p ${CERT_DIR}
CERT_FILE=${CERT_DIR}/server.crt
KEY_FILE=${CERT_DIR}/server.key

check_cert_expired() {
    openssl x509 -in "$1" -noout -checkend 2592000 >/dev/null 2>&1
}

generate_cert() {
    echo "Generating self-signed TLS certificate..."
    openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
        -keyout "${KEY_FILE}" \
        -out "${CERT_FILE}" \
        -subj "/C=FR/ST=PARIS/L=PARIS/O=42/OU=student/CN=${DOMAIN_NAME}"
}

if [ ! -f "$CERT_FILE" ] || [ ! -f "$KEY_FILE" ]; then
    generate_cert
else
    if ! check_cert_expired "$CERT_FILE"; then
        echo "TLS certificate expired — regenerating..."
        generate_cert
    else
        echo "Existing TLS certificate still valid."
    fi
fi

echo "Starting NGINX with TLS..."
exec nginx -g "daemon off;"
