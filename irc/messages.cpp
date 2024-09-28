
#include "inc/server.hpp"

// ----------------------------------------- Messages -------------------------------------


int	Server::send_msg_channel(Client& sender, Channel &chan, std::string msg)
{
	// send msg to all user in the channel
	for (std::vector<Client>::iterator it = chan.members.begin(); it != chan.members.end(); it++)
	{
		if (sender.get_socket() != it->get_socket())
			send_msg(it->get_socket(), msg);
	}
	return 0;
}

int	Server::send_msg(int dest_fd, std::string msg)
{
	// std::cout << dest_fd << " msg >> "<< msg;
	if (send(dest_fd, msg.c_str(), msg.size(), 0) == -1)
	{
		std::cout << "Send error to client [" << dest_fd << "]" << std::endl;
		return 1;
	}
	return 0;
}

std::string	Server::create_tag(Client& client)
{
	std::stringstream s;

	s << client.get_nickname() << "!" << client.get_username() << "@" << client.get_address() << ".IP";

	return s.str();
}

void	Server::send_reply(int code, Client &client, std::string arg, std::string msg)
{
	std::stringstream s;

	if (arg.empty())
		s << ":" << servername << " " << std::setw(3) << std::setfill('0') << code 
		<< " " << client.get_nickname() << " :" << msg << std::endl;
	else if (msg.empty())
		s << ":" << servername << " " << std::setw(3) << std::setfill('0') << code 
		<< " " << client.get_nickname() << " " << arg << std::endl;
	else
		s << ":" << servername << " " << std::setw(3) << std::setfill('0') << code 
		<< " " << client.get_nickname() << " " << arg << " :" << msg << std::endl;

	send_msg(client.get_socket(), s.str());
}


// ------------------------------------- Error --------------------------------------------------------------------------


void	Server::send_err(int code, Client &sender, std::string msg)
{
	std::stringstream s;

	s << ":" << servername << " " << code << " " << sender.get_nickname() << " :" << msg << std::endl;

	send_msg(sender.get_socket(), s.str());
}

void	Server::send_err(int code, Client &sender, std::string arg1, std::string msg)
{
	std::stringstream s;

	s << ":" << servername << " " << code << " " << sender.get_nickname() << " " << arg1 << " :" << msg << std::endl;

	send_msg(sender.get_socket(), s.str());
}


void	Server::send_err(int code, Client &sender, std::string arg1, std::string arg2, std::string msg)
{
	std::stringstream s;

	s << ":" << servername << " " << code << " " << sender.get_nickname() << " " << arg1 << " " << arg2 << " :" << msg << std::endl;

	send_msg(sender.get_socket(), s.str());
}


void	Server::send_err(int code, Client &sender, std::string arg1, std::string arg2, std::string arg3, std::string msg)
{
	std::stringstream s;

	s << ":" << servername << " " << code << " " << sender.get_nickname() << " " << arg1 << " " << arg2 << " " << arg3 << " :" << msg << std::endl;

	send_msg(sender.get_socket(), s.str());
}


// ------------------------------------- Notices --------------------------------------------------------------------------


void	Server::welcome_server(Client& client)
{
	std::stringstream ss;

	ss << "Welcome to the " << networkname << " IRC Network " <<  create_tag(client);
	send_reply(001, client, "", ss.str());

	ss.str("");

	ss << "Your host is " << servername << " running version " << version;
	send_reply(002, client, "", ss.str());


	ss.str("");

	ss << "This server was created " << datetime;
	send_reply(003, client, "", ss.str());

	list_server(client);
	modt_server(client);

}

void	Server::list_server(Client& client)
{
	std::stringstream ss;

	ss << "There are " << client_count() << " users on " << 1 << " servers " << datetime;
	send_reply(251, client, "", ss.str());

	ss.str("");

	ss << operator_count();
	send_reply(252, client, ss.str(), "operator(s) online");

	ss.str("");

	ss << channel_count();
	send_reply(254, client, ss.str(), "channels formed");

	ss.str("");

	ss << "I have " << client_count() << " clients and " << 1 << " servers " << datetime;
	send_reply(255, client, "", ss.str());

}

void	Server::modt_server(Client& client)
{

	send_reply(375, client, "", "- ScaleFactor.ma Message of the Day - ");

	// send_reply(372, client, "", "<!--          .-.           .-             .-.                         -->");
	// send_reply(372, client, "", "<!--    .--.-'             /              / -'           /             -->");
	// send_reply(372, client, "", "<!--   (  (_).-.  .-.     /   .-.     . -/--.-.  .-. ---/---.-._.).--. -->");
	// send_reply(372, client, "", "<!--    `-. (    (  |    /  ./.-'_   /  /  (  | (      /   (   )/      -->");
	// send_reply(372, client, "", "<!--  _    ) `---'`-'-'_/_.-(__.'    `.'    `-'-'`---'/     `-'/       -->");
	// send_reply(372, client, "", "<!-- (_.--'                                                            -->");

	// send_reply(372, client, "", "<!--              # #                      .-                                    .-   -->");
	// send_reply(372, client, "", "<!--    .---.     .-.    /      /         /  .        /           /             /  .  -->");
	// send_reply(372, client, "", "<!--   (     '   (  )   /      /.-.  #   /  /   .    /    .-.    /    .- -.    /  /   -->");
	// send_reply(372, client, "", "<!--    `-.  (     /   /     /    ) /   /  /   (    /    (   )  /     |  /    /  /    -->");
	// send_reply(372, client, "", "<!-- (     )  `---'   ' ----'`---- '---'  /    '._ /  ---'`--' / ___ _| / __ '  /     -->");
	// send_reply(372, client, "", "<!--  '---'                              /                                     /      -->");

	// send_reply(372, client, "", "<!--          # #                       .-                                  -->");
	// send_reply(372, client, "", "<!--         .-.     /      /          /  .-         /           /          -->");
	// send_reply(372, client, "", "<!--  .     (   )   /      /.-.   #   /  /     .    /    .-.    /           -->");
	// send_reply(372, client, "", "<!-- (         /   /     /    )  /   /  /     (    /    (   )  /       .-.  -->");
	// send_reply(372, client, "", "<!--  '-------'   ' ----'`---- -'---'  /      '._ /  ---'`--' / ___ __(___  -->");
	// send_reply(372, client, "", "<!--                                  /                                     -->");

	send_reply(372, client, "", "<!--                       ScaleFactor                     -->");
	send_reply(372, client, "", "- ");
	send_reply(372, client, "", "-  Welcome to the ScaleFactor.ma server of the Scale Factor IRC network ");
	send_reply(372, client, "", "-  ");
	send_reply(372, client, "", "-  The server is designed for quiet communication.");
	send_reply(372, client, "", "-  other use not according to the intended purpose will not be tolerated   ");
	send_reply(372, client, "", "-  You cannot change the network rules with any command !   ");
	send_reply(372, client, "", "-  ");

	send_reply(376, client, "", "End of /MOTD command.");

}

void	Server::list_channel(Client& client, Channel &chan)
{
	std::stringstream ss;
	std::stringstream ss2;

	ss2 << chan.get_topic();
	send_reply(332, client, ss.str(), ss2.str());

	ss.str("");
	ss << "#" << chan.get_name() << " " << chan.get_topic_info();
	send_reply(333, client, ss.str(), "");

	ss.str("");
	ss << "= #" << chan.get_name();
	ss2.str("");
	for (std::vector<Client>::iterator it = chan.members.begin(); it != chan.members.end(); it++)
	{
		if (chan.is_membre_mode(*it, 'o'))
			ss2 << "@";
		// ss2 << create_tag(*it) << " ";
		ss2 << it->get_nickname() << " ";
	}
	send_reply(353, client, ss.str(), ss2.str());

	ss.str("");
	ss << "#" << chan.get_name();
	send_reply(366, client, ss.str(), "End of /NAMES list.");

	ss.str("");
	ss << "#" << chan.get_name() << " +" << chan.get_mode();
	ss2.str("");
	send_reply(324, client, ss.str(), ss2.str());

	ss.str("");
	ss << "#" << chan.get_name() << " " << chan.get_time();
	send_reply(329, client, ss.str(), "");

	for (std::vector<Client>::iterator it = chan.members.begin(); it != chan.members.end(); it++)
	{
		ss.str("");
		ss << "#" << chan.get_name() << " ~" << it->get_username() << " " << it->get_address() << ".IP " << servername
		<< " " << it->get_nickname() << " " <<  it->get_mode();
		send_reply(352, client, ss.str(), it->get_realname());
	}

	ss.str("");
	ss << "#" << chan.get_name();
	send_reply(315, client, ss.str(), "End of /WHO list");
}


void	Server::list_channel_short(Client& client, Channel &chan)
{
	std::stringstream ss;

	for (std::vector<Client>::iterator it = chan.members.begin(); it != chan.members.end(); it++)
	{
		ss.str("");
		ss << "#" << chan.get_name() << " ~" << it->get_username() << " " << it->get_address() << ".IP " << servername
		<< " " << it->get_nickname() << " " <<  it->get_mode();
		send_reply(352, client, ss.str(), it->get_realname());
	}

	ss.str("");
	ss << "#" << chan.get_name();
	send_reply(315, client, ss.str(), "End of /WHO list");
}

void	Server::list_user(Client& client, Client &target_client)
{
	std::stringstream ss;

	ss << "~" << target_client.get_username() << " " << target_client.get_address() << ".IP " << servername
	<< " " << target_client.get_nickname() << " " <<  target_client.get_mode();
	send_reply(352, client, ss.str(), target_client.get_realname());

	send_reply(315, client, "", "End of /WHO list");

}
