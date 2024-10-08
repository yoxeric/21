
#include "../inc/server.hpp"

void Server::topic(Client& sender, std::string buffer)
{
	std::istringstream input(buffer);
	std::stringstream ss;
	std::stringstream _ss_;

	std::string chan_name;
	getline(input, chan_name, ' ');
	
	if(chan_name.empty())
	{
		send_err(461, sender, "TOPIC", "Not enough parameters");
		return ;
	}

	std::string topic;
	getline(input, topic, ' ');

	if(topic.size() > 1 && topic.front() == ':')
		topic = buffer.substr(buffer.find(":") + 1, buffer.length() - buffer.find(":"));


	if (chan_name.at(0) != '#')
	{
		send_err(403, sender, chan_name, "No such channel");
		return ;
	}
	else
		chan_name.erase(chan_name.begin());

	Channel* chan = find_channel(chan_name); 
	if (chan == NULL)
	{
		send_err(403, sender, chan_name, "No such channel");
		return ;
	}

	if (chan->is_mode('t'))
	{
		if (!chan->is_membre(sender.get_nickname()))
		{
			send_err(442, sender, chan_name, "You're not on that channel");
			return ;
		}
		if (!chan->is_membre_mode(sender, 'o'))
		{
			send_err(482, sender, chan_name, "You're not channel operator");
			return ;
		}
	}
	if(topic.empty())
	{
		ss << "#" << chan->get_name();
		_ss_ << chan->get_topic();
		send_reply(332, sender, ss.str(), _ss_.str());
		return ;
	}

	if(topic == ":")
	{
		chan->set_topic("");
		chan->set_topic_info(create_tag(sender), get_timestamp());
	}
	else
	{
		chan->set_topic(topic);
		chan->set_topic_info(create_tag(sender), get_timestamp());
	}

}
