# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Files
NAME = minishell
SRC = minishell.c \
	ft_atoi.c \
	ft_strjoin.c \
	ft_strdup.c \
	ft_memcpy.c \
	ft_strlen.c \
	ft_pcollector.c \
	pars.c \
	pars2.c
OBJ = $(SRC:.c=.o)

# Readline linking
LIBS = -lreadline -lncurses

# Build target
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
