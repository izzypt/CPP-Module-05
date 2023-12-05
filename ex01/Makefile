# Makefile
NAME = exercise01

# Compiler
CC = c++

# Source files
SRCS = main.cpp Bureaucrat.cpp Form.cpp

# Define the colors
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
NC=\033[0m #color reset value (No color)

$(NAME): $(SRCS)
		@echo "$(GREEN)\nCompiling ex01 with MakeFile...\n$(NC)"
		$(CC) $(SRCS)

# Rules
all: $(NAME)
		$(CC) $(SRCS) -o $(NAME)

clean:
		@echo "$(RED)\nRemoving ex01 with MakeFile...\n$(NC)"
		rm -f $(NAME)

re:
	make clean && make all