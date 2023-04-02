NAME = push_swap

CC = cc
SFLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h
LIBS = ft_printf/libftprintf.a

SRC = push_swap.c get_stack.c sort_stack.c\
	instructions1.c instructions2.c\
	ft_atoi.c ft_split.c ft_strlen.c


OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(SFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean re