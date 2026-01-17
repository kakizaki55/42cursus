
include ./srcs/.env

all: build run

build:
	mkdir -p $(DATA_PATH)/mariadb
	mkdir -p $(DATA_PATH)/wordpress
	docker-compose -f ./srcs/docker-compose.yml --env-file ./srcs/.env build --no-cache

run:
	docker-compose -f ./srcs/docker-compose.yml --env-file ./srcs/.env up -d

down:
	docker-compose -f ./srcs/docker-compose.yml --env-file ./srcs/.env down

re:
	mkdir -p $(DATA_PATH)/mariadb
	mkdir -p $(DATA_PATH)/wordpress
	docker-compose -f ./srcs/docker-compose.yml --env-file ./srcs/.env up -d --build

clean:
    docker-compose -f ./srcs/docker-compose.yml --env-file ./srcs/.env down --remove-orphans

fclean: clean
    # Remove named volumes belonging to this compose project (wipes WP files + DB)
    docker-compose -f ./srcs/docker-compose.yml --env-file ./srcs/.env down -v --remove-orphans
    # Remove images built for this project
    docker-compose -f ./srcs/docker-compose.yml --env-file ./srcs/.env down --rmi all --remove-orphans
    # If you still have bind-mount dirs (old setup), remove them too
    rm -rf $(DATA_PATH)

.PHONY: all down re clean fclean