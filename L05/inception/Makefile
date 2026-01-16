
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
	@docker stop $$(docker ps -qa) 2>/dev/null || true; \
	docker rm $$(docker ps -qa) 2>/dev/null || true; \
	docker rmi -f $$(docker images -qa) 2>/dev/null || true; \
	docker volume rm $$(docker volume ls -q) 2>/dev/null || true; \
	docker network rm $$(docker network ls -q) 2>/dev/null || true

fclean: clean
	@sudo chown -R minoka:minoka $(DATA_PATH) 2>/dev/null || true
	docker system prune -a -f --volumes
	rm -rf $(DATA_PATH)

.PHONY: all down re clean fclean