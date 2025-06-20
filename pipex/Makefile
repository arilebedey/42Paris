CC						= cc
CFLAGS					= -Wall -Wextra -Werror -I. -g
RM						= rm -rf
NAME					= pipex

SRCS					= srcs/main.c srcs/parse.c srcs/error.c srcs/free.c \
							srcs/processes.c utils/ft_split.c utils/ft_strjoin.c \
							utils/ft_strlen.c utils/ft_strncmp.c

OBJS					= $(SRCS:%.c=obj/%.o)

INCS					= pipex.h

# Rules
all:						${NAME}

obj:
							mkdir -p obj/srcs obj/utils

$(OBJS):				obj/%.o: %.c $(INCS) | obj
							$(CC) $(CFLAGS) -c $< -o $@

$(NAME):				$(OBJS)
							${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:	
							${RM} obj

fclean:					clean
							${RM} ${NAME}

re:						fclean all

rc:
							$(MAKE) re && $(MAKE) clean

.PHONY:					all clean fclean re rc
