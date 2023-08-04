NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror 
HEADER = philo.h

SRC = philo.c data.c utils.c actions.c get_fork.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ} ${HEADER}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
