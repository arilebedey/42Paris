CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
SRCS        = change_state.c \
              close_game.c \
              error2.c \
              error.c \
              free.c \
              init.c \
              load_images.c \
              main.c \
              on_gameplay.c \
              on_key_press.c \
              parse_chars.c \
              parse_map.c \
              read_file.c \
              render_map.c \
              update_animation.c \
              validate_path.c
SRCS_BONUS  = change_state.c \
              close_game.c \
              enemy_bonus.c \
              error2.c \
              error.c \
              free.c \
              init.c \
              load_images.c \
              main.c \
              on_gameplay.c \
              on_key_press.c \
              parse_chars_bonus.c \
              parse_map.c \
              read_file.c \
              render_map.c \
              update_animation_bonus.c \
              validate_path.c
OBJ_DIR     = obj
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS  = $(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.c=.o))
NAME        = so_long
NAME_BONUS  = so_long_bonus
LIBFT_PATH  = ./libft
LIBFT       = $(LIBFT_PATH)/libft.a
MLX_DIR     = ./minilibx
MLX_FLAGS   = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lbsd
MLX_MAKE    = $(MAKE) -C $(MLX_DIR)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(MLX_MAKE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_PATH)
	$(MLX_MAKE)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all bonus clean fclean re
