NAME := libftprintf.a

SRCS := ft_printf.c numbers.c pointers.c chars.c

OBJS := $(SRCS:.c=.o)

CC = cc
CFLAGS := -Wall -Werror -Wextra -I ./

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS}
		ar -rsc ${NAME} ${OBJS}

clean:	
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
