#Variables
PROG_NAME	= push_swap
NAME		= push_swap.a
INCLUDE		= include
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= cc -I
# CFLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS	= -g -fsanitize=address
RM			= rm -f
AR			= ar rc

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

#Sources

SRC_FILES	=	push_swap_utils \
				args_validation \

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			cp libft/libft.a .
			mv libft.a $(NAME)
			$(AR) $(NAME) $(OBJ)
			$(CC) $(CFLAGS) $(INCLUDE) main.c $(NAME) -o $(PROG_NAME)
			@echo "$(GREEN) $(NAME) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

$(OBJF):
			mkdir -p $(OBJ_DIR)

clean:
			$(RM) -rf $(OBJ_DIR)
			make clean -C $(LIBFT)
			@echo "$(BLUE) $(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)/libft.a
			$(RM) a.out
			$(RM) $(PROG_NAME)
			@echo "$(CYAN) $(NAME) executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			$(CC) $(CFLAGS) $(INCLUDE) main.c $(NAME) -o $(PROG_NAME)
			@echo "$(GREEN)Cleaned and rebuilt everything for  $(NAME)!$(DEF_COLOR)"

norm:
			norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

debug:		fclean all
			$(CC) $(CFLAGS) $(INCLUDE) $(DEBUG_FLAGS) main.c $(NAME) -o $(PROG_NAME)
			@echo "$(GREEN)Cleaned and rebuilt everything for  $(NAME) in debug mode!$(DEF_COLOR)"

.PHONY:		all clean fclean re norm debug