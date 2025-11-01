NAME	= skyscrapers_puzzle_solver
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3

SRC_DIR	= src

SRC		= \
		  arg_is_invalid.c	check_clue.c	\
		  parse_clue.c		solver.c		\
		  col_is_bad.c		row_is_bad.c	\
		  main.c

OBJS	= $(SRC:.c=.o)

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re

GREEN	= \e[32m
CYAN	= \e[36m
WHITE	= \e[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I. $^ -o $(NAME)
	@echo "Compiling $(GREEN)$(NAME)$(WHITE)..."

%.o: %.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@
	@echo "Compiling $(CYAN)$@$(WHITE)..."

fclean: clean
	@rm -f $(NAME)
	@echo "Removing $(GREEN)$(NAME)$(WHITE)..."

clean:
	@rm -f $(OBJS)
	@echo "Removing $(CYAN)object$(WHITE) files..."

re: fclean all
