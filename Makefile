NAME	= skyscrapers_puzzle_solver
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3

SRC_DIR		= src
SRC2_DIR	= src_bonus

SRC		= \
		  arg_is_invalid.c	check_clue.c	\
		  parse_clue.c		solver.c		\
		  col_is_bad.c		row_is_bad.c	\
		  main.c

SRC2	= \
		  ft_strlen.c		ft_factorial.c		\
		  free.c			parse_clue.c		\
		  generate_comb.c	set_permutation.c	\
		  solver.c			main.c				\
		  col_is_bad.c		row_is_bad.c

.PHONY = all clean fclean re bonus

all: $(NAME)

bonus: $(addprefix $(SRC2_DIR)/, $(SRC2))
	@$(CC) $(CFLAGS) -I. $^ -o $(NAME)_bonus
	@echo "Compiling $(NAME)_bonus..."

$(NAME): $(addprefix $(SRC_DIR)/, $(SRC))
	@$(CC) $(CFLAGS) -I. $^ -o $(NAME)
	@echo "Compiling $(NAME)..."

fclean: clean
	rm -f $(NAME) $(NAME)_bonus

clean:

re: fclean all
