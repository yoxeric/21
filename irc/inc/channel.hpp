#pragma once

#include <iostream>
#include <sstream> 
#include <vector>

#include "client.hpp"

class Channel
{
private:
	std::string name;
	std::string topic;
	std::string key;
	std::string mode;
	
	std::string time;

	std::string topic_user;
	std::string topic_time;

	int limit;

public:
	std::vector<Client> members;
	std::vector<std::string> invited;

	Channel();
	~Channel();

	void		add_membre(Client& client);
	void		remove_membre(Client& client);
	int			is_membre(std::string name);

	int			count_membres();
	int			count_operators();

	void		add_membre_mode(Client& client, char m);
	void		remove_membre_mode(Client& client, char m);
	int			is_membre_mode(Client& client, char m);

	void		add_invited(std::string s);
	void		remove_invited(std::string s);
	int			is_invited(std::string s);


	// ----------------------  Mode -----------------------


	void		add_mode(char m);
	void		remove_mode(char m);
	int			is_mode(char m);


	// ----------------------  Setter -----------------------


	void		set_mode(std::string str);
	void		set_name(std::string str);
	void		set_topic(std::string str);
	void		set_key(std::string str);
	void		set_limit(int limit);

	void 		set_time(std::string str);

	void		set_topic_info(std::string user, std::string time);


	// ----------------------  Getter -----------------------


	std::string	get_mode();
	std::string	get_name();
	std::string	get_topic();
	std::string	get_key();
	int			get_limit();

	std::string get_time();

	std::string get_topic_info();


	// ----------------------  Debug -----------------------


	void 		print();

};