CHM		=	./

SRCS	=	ft_conv_cs.c\
			ft_conv_p.c\
			ft_conv_diux.c\
			ft_putnbr.c\
			ft_di_2.c\
			ft_x_2.c\
			ft_parse.c\
			ft_parse2.c\
			ft_printf.c\
			ft_utile.c\
			ft_percent.c\

OBJS	= ${SRCS:.c=.o}

HEADERS	= ./includes./ft_printf.h

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

NAME	=	libftprintf.a

.c.o:
			${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
	rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
