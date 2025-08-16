

all:
	docker-compose -f ./srcs/docker-compose.yml up
down:
	docke-compose -f ./srcs/docker-compose.yml down
re:
	docker-compose up -f ./srcs/docker-compose.yml --build
clean:
	@docker stop $$(docker ps -qa);\
	docker rm $$(docker ps -qa);\
	docker rmi -f $$(docker images -qa);\
	docker volume rm $$(docker volume ls -q);\
	docker network rm $$(docker network ls -q);\
phony:
	all down re clean