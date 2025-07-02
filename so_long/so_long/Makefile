CC				= cc
CFLAGS		= -Wall -Wextra -Werror -g
SRCS			= srcs/main.c
OBJS			= $(SRCS:.c=.o)
NAME			= so_long
LIBFT_PATH	= ./libft
LIBFT			= $(LIBFT_PATH)/libft.a
MLX_DIR		= ./minilibx
MLX_FLAGS	= -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lbsd
MLX_MAKE	= $(MAKE) -C $(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS)
						$(MAKE) -C $(LIBFT_PATH)
						$(MLX_MAKE)
						$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
						$(CC) $(CFLAGS) -c $< -o $@

clean:
						@rm -f $(OBJS)
						@$(MAKE) -C $(LIBFT_PATH) clean
						@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
						@rm -f $(NAME)
						@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re












































