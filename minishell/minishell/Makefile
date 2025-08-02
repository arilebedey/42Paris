.PHONY: all clean fclean re debug quiet

CC          = cc
CFLAGS      = -Wall -Werror -Wextra -MMD -MP
AR          = ar -rcs
NAME        = minishell

UNAME_S     := $(shell uname -s)

ifeq ($(UNAME_S),darwin)
    READLINE_DIR := $(shell brew --prefix readline)
    INCLUDES += -I$(READLINE_DIR)/include
    READLINE_LIBS := -L$(READLINE_DIR)/lib -lreadline -lncurses
else
    READLINE_LIBS := -lreadline
endif

LIBFT_DIR   = ./libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

INCLUDES    = -I$(LIBFT_DIR)/includes \
              -I./includes

FILES       = main
SRC_DIR     = src/
SRC_FILES   = $(addsuffix .c, $(FILES))
SRC         = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR     = obj/
OBJ         = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

all: $(LIBFT_A) $(NAME)
	@echo "-> minishell compiled <-"

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/builtin
	@mkdir -p $(OBJ_DIR)/lexing
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/signal
	@mkdir -p $(OBJ_DIR)/exec
	@mkdir -p $(OBJ_DIR)/expand

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT_A) $(READLINE_LIBS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

debug: all
