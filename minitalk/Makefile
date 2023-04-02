NAME_C = client
NAME_S = server
NAME_CB = client_bonus
NAME_SB = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = minitalk.h
LIBS = utils/libftprintf.a

SRC_C = client.c utils/ft_atoi.c
SRC_S = server.c utils/ft_power.c
SRC_CB = client_bonus.c utils/ft_atoi.c utils/ft_strlen.c
SRC_SB = server_bonus.c utils/ft_power.c

OBJ_C = ${SRC_C:.c=.o}
OBJ_S = ${SRC_S:.c=.o}
OBJ_CB = ${SRC_CB:.c=.o}
OBJ_SB = ${SRC_SB:.c=.o}


all: $(NAME_C) $(NAME_S)

$(NAME_C): $(OBJ_C)
	$(CC) $(OBJ_C) $(LIBS) -o $(NAME_C)

$(NAME_S): $(OBJ_S)
	$(CC) $(OBJ_S) $(LIBS) -o $(NAME_S)

bonus: $(NAME_CB) $(NAME_SB)

$(NAME_CB): $(OBJ_CB)
	$(CC) $(OBJ_CB) $(LIBS) -o $(NAME_CB)

$(NAME_SB): $(OBJ_SB)
	$(CC) $(OBJ_SB) $(LIBS) -o $(NAME_SB)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_C) $(OBJ_S) $(OBJ_CB) $(OBJ_SB)

fclean: clean
	rm -f $(NAME_C) $(NAME_S) $(NAME_CB) $(NAME_SB)

re: fclean all

.PHONY: all clean re
