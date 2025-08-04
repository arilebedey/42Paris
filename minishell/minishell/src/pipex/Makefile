CC						= cc
CFLAGS	  		= -Wall -Wextra -Werror -I. -I./libft -g
RM						= rm -rf
NAME					= pipex
BONUS					= pipex_bonus
LIBFT_DIR     = libft
LIBFT_A       = $(LIBFT_DIR)/libft.a

SRCS					= main.c parse.c error.c free.c processes.c 

SRCSBONUS     = main_bonus.c parse_bonus.c print_bonus.c exit_bonus.c \
								free_struct_bonus.c init_struct_bonus.c connect_bonus.c \
								close_bonus.c pipeline_bonus.c children_bonus.c \
								exec_cmd_bonus.c parse2_bonus.c

OBJDIR  = obj
OBJDIRBONUS = obj_bonus

OBJS    = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
OBJSBONUS   = $(addprefix $(OBJDIRBONUS)/, $(SRCSBONUS:.c=.o))

INCS    = pipex.h
INCSBONUS   = pipex_bonus.h

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

$(OBJDIRBONUS)/%.o: %.c $(INCSBONUS) | $(OBJDIRBONUS)
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
