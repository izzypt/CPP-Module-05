# Makefile
# Makefile
NAME = exercise01

# Compiler
CC = c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

# Source files
SRCS = main.cpp Bureaucrat.cpp Form.cpp

# Colors
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
NC=\033[0m #color reset value (No color)

# Variables
$(NAME):
		@echo "$(GREEN)Compiling ex00 with MakeFile...$(NC)"
		$(CC) $(SRCS) -o $(NAME)

# Rules
all: $(NAME)

clean: 
	@echo "$(RED)Removing ex00...$(NC)"
	rm -f $(NAME)

re: clean all


.PHONY: all clean re