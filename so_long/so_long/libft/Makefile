NAME := libft.a

LIBC :=				ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
							ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
							ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
							ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
							ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c
ADDITIONAL :=	ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
							ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_striteri.c
GNL      :=   get_next_line.c get_next_line_utils.c

SRCS := $(LIBC) $(ADDITIONAL) $(GNL)
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
