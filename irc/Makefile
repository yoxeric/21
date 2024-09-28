NAME = ircserv
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ft_irc.cpp poll.cpp client.cpp channel.cpp server.cpp parse.cpp messages.cpp \
 		cmds/cap.cpp cmds/invite.cpp cmds/join.cpp cmds/kick.cpp cmds/list.cpp \
 		cmds/mode.cpp cmds/oper.cpp cmds/part.cpp cmds/pass.cpp cmds/ping.cpp \
 		cmds/privmsg.cpp cmds/quit.cpp cmds/topic.cpp cmds/user.cpp cmds/who.cpp cmds/nick.cpp 

HEADER = inc/poll.hpp inc/client.hpp inc/channel.hpp inc/server.hpp

OBJ = ${SRC:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	