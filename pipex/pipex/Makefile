CC						= cc
CFLAGS	  		= -Wall -Wextra -Werror -I. -I./libft -g
RM						= rm -rf
NAME					= pipex
LIBFT_DIR     = libft
LIBFT_A       = $(LIBFT_DIR)/libft.a

SRCS    = main.c parse.c print_exit.c free_struct.c init_struct.c \
          connect.c close.c pipeline.c children.c exec_cmd.c

OBJDIR  = obj
OBJS    = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

INCS    = pipex.h

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c $(INCS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

clean:
	$(RM) $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
