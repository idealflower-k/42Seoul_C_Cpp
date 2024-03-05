FROM alpine:3.17

WORKDIR /nginx

RUN apk update && \
    apk add --no-cache \
    nginx \
    openssl

RUN mkdir -p /etc/nginx/ssl

RUN ln -sf /dev/stdout /var/log/nginx/access.log && \
    ln -sf /dev/stderr /var/log/nginx/error.log

COPY ./conf/nginx.conf /etc/nginx/http.d/default.conf

COPY ./tools/generate_ssl.sh /nginx

RUN chmod +x /nginx/generate_ssl.sh

EXPOSE 443

CMD [ "/nginx/generate_ssl.sh" ]
