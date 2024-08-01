NAME		=	fdf

LIBFT_PATH	=	./libs/libft
MLX_PATH	=	./libs/mlx-linux

INCLUDES	=	-I includes -I $(LIBFT_PATH)/includes -I $(MLX_PATH)

# CFLAGS		=	-Wall -Werror -Wextra $(INCLUDES)
CFLAGS		= 	$(INCLUDES)

LIBS_PATH	=	-L$(LIBFT_PATH) -L$(MLX_PATH)

LIBS		=	-lft -lmlx -lmlx_Linux -lX11 -lXext -Imlx -lXext

MLX			=	libmlx.a libmlx_Linux.a 

FILES 		=	main.c 

SRCS		=	$(addprefix src/,$(FILES))

OBJS		=	$(SRCS:.c=.o)

CC		=	clang

CP		=	@cp -r

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) --no-print-directory
	$(MAKE) -C $(MLX_PATH) --no-print-directory
	$(CC) $(OBJS) -o $(NAME) $(LIBS_PATH) $(LIBS)

clean:
	$(RM) $(OBJS) $(MLX)
	$(MAKE) clean -C $(LIBFT_PATH) --no-print-directory
	$(MAKE) clean -C $(MLX_PATH) --no-print-directory

fclean:
	$(RM) $(OBJS) $(NAME) $(MLX)
	$(MAKE) fclean -C $(LIBFT_PATH) --no-print-directory
	$(MAKE) fclean -C $(MLX_PATH) --no-print-directory

re: fclean all 

.PHONY: all clean fclean re