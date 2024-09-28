
#include "inc/server.hpp"

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "usage: ./ircserv <port> <password>" << std::endl;
		return 1;
	}

	int server_socket;
	Server server;

	server_socket = server.pool.make_server_socket(atoi(av[1]));
	if (server_socket < 0)
		return 1;

    server.pool.init_poll(server_socket);
    server.init_server(av[2]);

    while (1)
    {
        // Poll sockets to see if they are ready
    	int ready_fds = poll(server.pool.get_poll(), server.pool.get_size(), -1);
		if (ready_fds == 0)
    	{
			std::cout << "waiting..." << std::endl;
			continue ;
    	}
    	else if (ready_fds < 0)
    	{
			std::cout << "Poll Error " << std::endl;
			return 1;
		}
		if (server.pool.check_pollin(0))
		{
			int client_socket = server.pool.accept_new_connection(server_socket);
			server.add_client(client_socket);
			server.send_msg(client_socket, "connected\n");
		}
		else
		{
			for (int i = 1; i < server.pool.get_size(); i++)
			{
				int client_socket = server.pool.get_socket(i);
				if (server.pool.check_pollhup(i))
					server.quit( *server.find_client(client_socket), "QUIT : client died");
				else if (server.pool.check_pollin(i))
				{
					std::string msg = server.pool.read_data(i);
					server.split_input(i, msg);
				}
			}
		}
	}
	close(server_socket);
	return 0;
}
