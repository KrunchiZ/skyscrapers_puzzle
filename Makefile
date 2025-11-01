NAME	= skyscrapers_puzzle_solver
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3

SRC_DIR		= src

SRC		= \
		  arg_is_invalid.c	check_clue.c	\
		  parse_clue.c		solver.c		\
		  col_is_bad.c		row_is_bad.c	\
		  main.c

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(SRC)

$(NAME): $(addprefix $(SRC_DIR)/, $(SRC))
	@$(CC) $(CFLAGS) -I. $^ -o $(NAME)
	@echo "Compiling $(NAME)..."

fclean: clean
	rm -f $(NAME) $(NAME)_bonus

clean:

re: fclean all
