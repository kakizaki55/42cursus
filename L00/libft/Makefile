
SRC			= 	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strnstr.c	\
				ft_atoi.c
# # SRC			= *.c
# SRCS		= $(./*.c)
SRCS		= ${addprefix ${PRE}, ${SRC}}
OBJS		= ${SRCS:.c=.o}
PRE			=	./
HEAD		=	libft.h
NAME		=	libft.a
AR			=	ar rc
LIB			=	ranlib
CC			=	cc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
all:		${NAME}
.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			${LIB} ${NAME}
re:			fclean all
clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
