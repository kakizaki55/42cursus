NAME		=	fdf

LIBFT_PATH	=	./libs/libft
MLX_PATH	=	./libs/mlx-linux

INCLUDES	= 	-I includes -I $(LIBFT_PATH)/includes -I $(MLX_PATH)

# CFLAGS		=	-Wall -Werror -Wextra $(INCLUDES)
CFLAGS		= 	$(INCLUDES)
LIBS_PATH	=	-L$(LIBFT_PATH) -L$(MLX_PATH)
DEBUG_FLAGS	=	-g -fsanitize=address
LIBS		=	-lft -lmlx -lmlx_Linux -lX11 -lXext -Imlx -lXext -lm
MLX			=	libmlx.a libmlx_Linux.a
SRCS		=	$(addprefix src/,$(FILES))
OBJS		=	$(SRCS:.c=.o)
CC			=	clang
FILES 		=	main.c utils.c parse_map.c draw.c cleanup.c hooks.c

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

# %.o:%.c
# 	$(CC) -g3 $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(OBJS) -o $(NAME) $(LIBS_PATH) $(LIBS)
	@echo "$(GREEN)<-----------------$(NAME) compiled!------------------>$(DEF_COLOR)"

clean:
	$(RM) $(OBJS) $(MLX)
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(MLX_PATH)
	@echo "$(CYAN)<--------$(NAME) object files cleaned!-------->$(DEF_COLOR)"

fclean:
	$(RM) $(OBJS) $(NAME) $(MLX)
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(MLX_PATH)
	@echo "$(CYAN)<------$(NAME) executable files cleaned!------>$(DEF_COLOR)"

re: fclean all

debug: $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(DEBUG_FLAGS) $(OBJS) -o $(NAME) $(LIBS_PATH) $(LIBS)

	@echo "$(MAGENTA)<------$(GREEN)Cleaned and rebuilt everything for $(NAME) in debug mode!$(MAGENTA)------>$(DEF_COLOR)"

.PHONY: all clean fclean re