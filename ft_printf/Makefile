LIB := libftprintf.a

SRCS := ft_printf.c numbers.c pointers.c

OBJS := $(SRCS:.c=.o)

CC = gcc
CFLAGS := -Wall -Werror -Wextra -I ./

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

${LIB}:	${OBJS}
		ar -rsc ${LIB} ${OBJS}

all:	${LIB}

clean:	
		rm -f ${OBJS}

fclean:	clean
		rm -f ${LIB}

re:	fclean all

.PHONY: all clean fclean re
