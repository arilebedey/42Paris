DATA_DIR = $(HOME)/data

all: setup build up

setup:
	@mkdir -p $(DATA_DIR)/mariadb
	@mkdir -p $(DATA_DIR)/wordpress

build:
	docker compose -f srcs/docker-compose.yml build

up:
	docker compose -f srcs/docker-compose.yml up -d

down:
	docker compose -f srcs/docker-compose.yml down

clean: down
	docker compose -f srcs/docker-compose.yml down -v --rmi all
	docker run --rm -v mariadb_data:/data alpine sh -c "rm -rf /data/*" 2>/dev/null || true
	docker run --rm -v wordpress_data:/data alpine sh -c "rm -rf /data/*" 2>/dev/null || true

fclean: clean
	docker run --rm -v mariadb_data:/data alpine sh -c "rm -rf /data/*" 2>/dev/null || true
	docker run --rm -v wordpress_data:/data alpine sh -c "rm -rf /data/*" 2>/dev/null || true

re: fclean all

.PHONY: all setup build up down clean fclean re
