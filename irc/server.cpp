
#include "inc/server.hpp"


std::string Server::get_time()
{
	time_t rawtime;
  	time (&rawtime);
  	struct tm *timeinfo = localtime (&rawtime);

    char buffer [100];
  	strftime(buffer, sizeof(buffer), "%X %h%e %Y",timeinfo);
  	return (std::string(buffer));
}


std::string Server::get_timestamp()
{
	std::time_t t = std::time(0);
    std::stringstream s;
    s << t ;
  	return (s.str());
}

std::string Server::generate_name()
{
	int nb = client_count();
    std::stringstream s;
    s << "user" << std::setw(4) << std::setfill('0') << nb;
    while (true)
    {
    	Client* user = find_client(s.str());
		if (user == NULL)
			break ;
		nb++;
		s.str("");
    	s << "user" << std::setw(4) << std::setfill('0') << nb;
    }
  	return (s.str());
}

std::string Server::get_ip()
{
	char host[256];
    struct hostent *host_entry;

    // Get the local hostname
    if (gethostname(host, sizeof(host)) == -1) {
        perror("gethostname");
        return "";
    }

    // Get host entry for the local hostname
    if ((host_entry = gethostbyname(host)) == NULL) {
        perror("gethostbyname");
        return "";
    }

    // Convert the IP address from binary form to string
    std::string ip_address = inet_ntoa(*(struct in_addr *)host_entry->h_addr_list[0]);
    return (std::string(host));
}

// -----------------------------------  Server --------------------------------------

Server::Server()
{
	clients.reserve(10);
	channels.reserve(10);
	networkname = "";
	servername = "";
	datetime = "";
	password = "";
	version = "";
}

Server::~Server()
{

}

void	Server::init_server(char* pass)
{
	networkname = "Scale Factor Communication";
	servername = get_ip();
	datetime = get_time();
	password = pass;
	version = "1.0.1";
}

// ----------------------------------- Channel -------------------------------------------


Channel*	Server::add_channel(std::string name)
{
	Channel chan;
	chan.set_name(name);
	chan.set_limit(1024);
	chan.set_time(get_timestamp());

	channels.push_back(chan);
	return (&channels.back());
}

Channel*	Server::find_channel(std::string name)
{
	for (std::vector<Channel>::iterator it = channels.begin(); it != channels.end(); it++)
	{
		if (it->get_name() == name)
		{
			return (&(*it));
		}
	}
	return (NULL);
}

void	Server::remove_channel(Channel &chan)
{
	for (std::vector<Channel>::iterator it = channels.begin(); it != channels.end(); it++)
	{
		if (it->get_name() == chan.get_name())
		{
			channels.erase(it);
			break ;
		}
	}
}


int			Server::channel_count()
{
	return (channels.size());
}


// ----------------------------------- Client -------------------------------------------



Client*	Server::add_client(int socket)
{
	Client client;
	client.set_socket(socket);
	client.set_registred(0);
	client.set_nickname(generate_name());
	if (operator_count() == 0)
		client.set_mode("o");
	
	clients.push_back(client);
	return (&clients.back());
}

Client*	Server::find_client(int socket)
{
	for (std::vector<Client>::iterator it = clients.begin(); it != clients.end(); it++)
	{
		if (it->get_socket() == socket)
		{
			return (&(*it));
		}
	}
	return (NULL);
}

Client*	Server::find_client(std::string name)
{
	// check if anyone has the same username
	for (std::vector<Client>::iterator it = clients.begin(); it != clients.end(); it++)
	{
		if (it->get_nickname() == name)
		{
			return (&(*it));
		}
	}
	return (NULL);
}

void	Server::remove_client(Client &client)
{
	int sock = client.get_socket();
	for (std::vector<Client>::iterator it = clients.begin(); it != clients.end(); it++)
	{
		if (it->get_socket() == sock)
		{
			clients.erase(it);
			break ;
		}
	}
	pool.remove_from_poll(sock);
}

int			Server::client_count()
{
	return (clients.size());
}

int			Server::operator_count()
{
	int count = 0;
	for (std::vector<Client>::iterator it = clients.begin(); it != clients.end(); it++)
	{
		if (it->is_mode('o'))
			count++;
	}
	return (count);
}


// ----------------------------------- Debug -------------------------------------------



void Server::print()
{
	std::cout << "networkname : " << networkname << std::endl;
	std::cout << "servername : " << servername << std::endl;
	std::cout << "datetime : " << datetime << std::endl;
	std::cout << "version : " << version << std::endl;

	std::cout << "----------------- all channels" << std::endl;
	int i = 0;

	for (std::vector<Channel>::iterator it = channels.begin(); it != channels.end(); it++)
	{
		std::cout << "-------- channel nb." << i << std::endl;
		it->print();
		i++;
	}

	std::cout << "----------------- all clients" << std::endl;
	i = 0;

	for (std::vector<Client>::iterator it = clients.begin(); it != clients.end(); it++)
	{
		std::cout << "-------- client nb." << i << std::endl;
		it->print();
		i++;
	}
}


