NAME	= skyscrapers_puzzle_solver
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Ofast -g0

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
	@printf "Compiling $(GREEN)$(NAME)$(WHITE)...\n"

%.o: %.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@
	@printf "Compiling $(CYAN)$@$(WHITE)...\n"

fclean: clean
	@rm -f $(NAME)
	@printf "Removing $(GREEN)$(NAME)$(WHITE)...\n"

clean:
	@rm -f $(OBJS)
	@printf "Removing $(CYAN)object$(WHITE) files...\n"

re: fclean all
