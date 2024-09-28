
#include "../inc/server.hpp"

int Server::cap(Client& sender, std::string buffer)
{
	std::istringstream input(buffer);
	std::string subcommand;
	std::stringstream ss;

	getline(input, subcommand, ' ');
	if(subcommand.empty())
	{
		send_err(410, sender, subcommand, "Invalid CAP command");
		return 1;
	}
	if(!subcommand.compare("LIST") || !subcommand.compare("LS"))
	{
		ss << "CAP * " << subcommand << " :"<< std::endl;
		send_msg(sender.get_socket(), ss.str());
	}
	else if(!subcommand.compare("REQ"))
	{
		ss << "CAP * ACK " << buffer.substr(buffer.find(":"), buffer.length() - buffer.find(":")) << std::endl;
		send_msg(sender.get_socket(), ss.str());
	}
	else if(!subcommand.compare("END"))
	{
		return 1;
	}
	else
	{
		send_err(410, sender, subcommand, "Invalid CAP command");
		return 1;
	}
	return 0;
}
