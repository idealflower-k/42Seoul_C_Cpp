DC = docker compose
BUILD_FLAGS = --no-cache
UP_FLAGS = -d --build
COMPOSE_PATH = srcs/docker-compose.yml

all: build up

build:
	$(DC) -f $(COMPOSE_PATH) build $(BUILD_FLAGS)

up:
	$(DC) -f $(COMPOSE_PATH) up $(UP_FLAGS)

down:
	$(DC) -f $(COMPOSE_PATH) down

down-v:
	$(DC) -f $(COMPOSE_PATH) down -v

logs:
	$(DC) -f $(COMPOSE_PATH) logs

re: down all

clean: down-v
	docker image prune -a
	sudo chown -R admin /home/sanghwal/data/mariadb_data/ /home/sanghwal/data/wordpress_data/
	rm -rf /home/sanghwal/data/mariadb_data/* /home/sanghwal/data/wordpress_data/*

nginx-logs:
	$(DC) -f $(COMPOSE_PATH) logs nginx

wordpress-logs:
	$(DC) -f $(COMPOSE_PATH) logs wordpress

mariadb-logs:
	$(DC) -f $(COMPOSE_PATH) logs mariadb

.PHONY: all build up down logs re clean nginx-logs wordpress-logs mariadb-logs
