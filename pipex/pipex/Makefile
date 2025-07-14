CC						= cc
CFLAGS	  		= -Wall -Wextra -Werror -I. -I./libft -g
RM						= rm -rf
NAME					= pipex
BONUS					= pipex_bonus
LIBFT_DIR     = libft
LIBFT_A       = $(LIBFT_DIR)/libft.a

SRCS    = main.c parse.c print.c exit.c free_struct.c init_struct.c \
          connect.c close.c pipeline.c children.c exec_cmd.c parse2.c
SRCSBONUS = main.c parse.c print.c exit.c free_struct.c init_struct.c \
            connect.c close.c pipeline.c children.c exec_cmd.c parse2.c

OBJDIR  = obj
OBJDIRBONUS  = obj_bonus

OBJS    = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
OBJSBONUS   = $(addprefix $(OBJDIRBONUS)/, $(SRCSBONUS:.c=.o))

INCS    = pipex.h

all: $(LIBFT_A) $(NAME)

bonus: $(LIBFT_A) $(BONUS)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIRBONUS):
	mkdir -p $(OBJDIRBONUS)

$(OBJDIR)/%.o: %.c $(INCS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIRBONUS)/%.o: %.c $(INCS) | $(OBJDIRBONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(BONUS): $(OBJSBONUS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJSBONUS) $(LIBFT_A) -o $(BONUS)

clean:
	$(RM) $(OBJDIR) $(OBJDIRBONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
