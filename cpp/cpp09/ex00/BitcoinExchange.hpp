
#include <iostream>
#include <fstream> 
#include <algorithm> // for lower_bound, upper_bound and sort

#include <vector>
#include <map>

#include <time.h>

class BitcoinExchange
{
private:
	std::map<std::string, float> map;

    // std::vector<std::string> time;
    // std::vector<float> price;

public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange &src);
	~BitcoinExchange();


	int		register_data(std::string data);

	int		parse_time(std::string time);

	int		calculate_money(std::string txt);

	float	Time2Price(std::string s);


	// float	Time2Price(std::string s);
	// int		getSize();

	// void	addTime(std::string s);
	// void	addPrice(float p);

	// void	setTime(int index, std::string s);
	// std::string	getTime(int index);

	// void	setPrice(int index, float p);
	// float	getPrice(int index);
};
