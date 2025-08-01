CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -pthread
RM          = rm -rf
NAME        = philo

SRC_DIR     = philo_base
OBJ_DIR     = obj

SRCS        = actions.c exit.c init.c libft.c main.c monitor.c print.c threads.c time.c
OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o)

INCS        = $(SRC_DIR)/philo.h

all:        $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): $(INCS)

$(NAME):    $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean:     clean
	$(RM) $(NAME)

re:         fclean all

rc:
	$(MAKE) re && $(MAKE) clean

.PHONY:     all clean fclean re rc
