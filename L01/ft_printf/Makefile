#Variables

NAME		= libftprintf.a
INCLUDE		= include
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I 
# this is just for testing out and development must change with proper flags
# CFLAGS		= -I
DEBUG_FLAGS	= -I -g -fsanitize=address
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

SRC_FILES	=	ft_printf \
				ft_printf_utils \
				ft_print_str \
				ft_print_address 


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
# cc -I include main.c libftprintf.a
			@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

$(OBJF):
			mkdir -p $(OBJ_DIR)

clean:
			$(RM) -rf $(OBJ_DIR)
			make clean -C $(LIBFT)
			@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)/libft.a
			$(RM) a.out
			@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
# cc -I include main.c libftprintf.a
			@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
			norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

debug:		fclean all
# $(CC) $(DEBUG_FLAGS) -I include libftprintf.a
			@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf in debug mode!$(DEF_COLOR)"

.PHONY:		all clean fclean re norm debug