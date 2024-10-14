NAME		=	philo

INCLUDES	= 	-I includes
# CFLAGS		=	-Wall -Werror -Wextra $(INCLUDES)
CFLAGS		= 	$(INCLUDES)
DEBUG_FLAGS	=	-fsanitize=address
OBJ_DIR		=	obj
SRC_DIR		=	src
SRCS		=	$(shell find $(SRC_DIR) -name '*.c')
OBJS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
RM			=	rm -rf
CC			=	clang


# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)<-----------------$(NAME) compiled!------------------>$(DEF_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	@echo "$(CYAN)<--------$(NAME) object files cleaned!-------->$(DEF_COLOR)"

fclean:
	$(RM) $(OBJ_DIR) $(NAME)
	@echo "$(CYAN)<------$(NAME) executable files cleaned!------>$(DEF_COLOR)"

re: fclean all

debug: fclean $(OBJS)
	$(CC) $(DEBUG_FLAGS) $(OBJS) -o $(NAME)
	@echo "$(MAGENTA)<------$(GREEN)Cleaned and rebuilt everything for $(NAME) in debug mode!$(MAGENTA)------>$(DEF_COLOR)"

.PHONY: all clean fclean re debug