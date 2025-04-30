LIB := libftprintf.a

SRCS := ft_printf.c
# ADDITIONAL :=	

# SRCS := $(LIBC) $(ADDITIONAL)
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
