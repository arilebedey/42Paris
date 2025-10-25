NAME = bsp

SRC_DIR = .
INC_DIR = .
OBJ_DIR = obj

SRCS = main.cpp \
			 Fixed.cpp \
			 bsp.cpp \
			 Point.cpp

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -I$(INC_DIR) -MMD -MP
RM = rm -rf

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR) .cache

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
