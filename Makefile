NAME	= rush-01
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3

SRC_DIR	= src
SRC		= \
		  arg_is_invalid.c	ft_strlen.c		\
		  parse_clue.c		solver.c		\
		  col_is_bad.c		row_is_bad.c	\
		  check_clue.c		main.c

.PHONY = all clean fclean re bonus

vpath %.c $(SRC_DIR)

all: $(NAME)

bonus: all

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) -I. $^ -o $(NAME)
	@echo "Compiling Rush-01..."

fclean: clean
	rm -f $(NAME)

clean:

re: fclean all
