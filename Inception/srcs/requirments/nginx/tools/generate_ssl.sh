#!/bin/sh

openssl req -x509 -nodes -days 365 \
-subj "/C=KR/L=Seoul/O=42Seoul/CN=sanghwal.42.fr" \
-addext "subjectAltName=DNS:sanghwal.42.fr" \
-newkey rsa:2048 \
-keyout /etc/ssl/private/sanghwal.42.fr.key \
-out /etc/ssl/certs/sanghwal.42.fr.crt;

exec nginx -g "daemon off;"
