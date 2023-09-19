NAME = megaphone
CC = c++
SFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

OBJ = ${SRC:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
