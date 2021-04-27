SRC 	=	ft_strlen.c		ft_strchr.c		printf.c		\
			print_char.c	print_str.c		print_void.c	\
			print_int.c		print_unsint.c	print_hex.c		\
			print_hex_big.c	print_flags.c	zero_list.c		\
			maxint.c		converter.c		ft_putnbr_int.c	\
			ft_putnbr_uns.c	converter_big.c

OBJ		= ${patsubst %.c, %.o, ${SRC}}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a

HEADERS	=	printf.h		print_hex.h	print_hex_big.h	\
		 	print_int.h		print_str.h	print_unsint.h	\
			print_void.h

all:		${NAME}

${NAME}:	${OBJ} ${HEADERS}
		ar rcs ${NAME} $?

%.o:	%.c 
		${CC} ${CFLAGS} -c $< -o $@

clean:
		rm -rf ${OBJ}

fclean:		clean
		rm -rf ${NAME}

re:			fclean all

.PHONY:	all clean fclean re

