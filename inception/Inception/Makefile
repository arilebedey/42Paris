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

fclean: clean
	@rm -rf $(DATA_DIR)

re: fclean all

.PHONY: all setup build up down clean fclean re
