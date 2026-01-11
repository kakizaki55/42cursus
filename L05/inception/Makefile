
all:
	mkdir -p /home/minoka/data/mariadb
	mkdir -p /home/minoka/data/wordpress
	echo "127.0.0.1 mkakizak.42.fr" | sudo tee -a /etc/hosts
	docker-compose -f ./srcs/docker-compose.yml up -d

down:
	docker-compose -f ./srcs/docker-compose.yml down

re:
	mkdir -p /home/minoka/data/mariadb
	mkdir -p /home/minoka/data/wordpress
	docker-compose -f ./srcs/docker-compose.yml up -d --build

clean:
	@docker stop $$(docker ps -qa) 2>/dev/null || true; \
	docker rm $$(docker ps -qa) 2>/dev/null || true; \
	docker rmi -f $$(docker images -qa) 2>/dev/null || true; \
	docker volume rm $$(docker volume ls -q) 2>/dev/null || true; \
	docker network rm $$(docker network ls -q) 2>/dev/null || true

fclean: clean
	sudo rm -rf /home/minoka/data

.PHONY: all down re clean fclean