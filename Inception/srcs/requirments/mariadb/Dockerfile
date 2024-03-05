FROM alpine:3.17

WORKDIR /mariadb

COPY ./conf/my.cnf /etc/

COPY ./tools/init_mariadb.sh .

RUN apk update && apk upgrade && apk add mariadb mariadb-client

RUN apk add --no-cache dumb-init

EXPOSE 3306

RUN chmod +x /mariadb/init_mariadb.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD [ "/mariadb/init_mariadb.sh" ]
