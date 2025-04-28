#!/bin/bash

find /home/alebedev/Code/42/libft/tests -type f -exec sed -i 's/#include "libft.h"/#include "..\/libft\/libft.h"/g' {} \;

# Colors for better visibility
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Function name to test (passed as argument)
FUNC_NAME=$1

if [ -z "$FUNC_NAME" ]; then
    echo -e "${RED}Please provide a function name (e.g. ft_strlen)${NC}"
    exit 1
fi

# Remove the 'ft_' prefix to get the base name
BASE_NAME=${FUNC_NAME#ft_}

# Check if function and test files exist
FUNC_FILE="./libft/${FUNC_NAME}.c"
LEN_FILE="./libft/ft_strlen.c"
TEST_FILE="./tests/${FUNC_NAME}_test.c"
HEADER_FILE="./libft/libft.h"

if [ ! -f "$FUNC_FILE" ]; then
    echo -e "${RED}Error: Function file $FUNC_FILE not found${NC}"
    exit 1
fi

if [ ! -f "$TEST_FILE" ]; then
    echo -e "${RED}Error: Test file $TEST_FILE not found${NC}"
    exit 1
fi

if [ ! -f "$HEADER_FILE" ]; then
    echo -e "${RED}Error: Header file $HEADER_FILE not found${NC}"
    exit 1
fi

echo -e "${GREEN}Compiling $FUNC_NAME with its test...${NC}"

# Compile the function with its test
cc -Wall -Werror -Wextra -lbsd "$FUNC_FILE" "$TEST_FILE" "$LEN_FILE" -o a.out
# cc -Wall -Werror -Wextra -lbsd "$FUNC_FILE" "$TEST_FILE" -o a.out

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Compilation successful! Running tests...${NC}"
    echo "----------------------------------------"
    # Run the executable
    ./a.out
    echo "----------------------------------------"
    echo -e "${GREEN}Test execution completed.${NC}"
else
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
fi
