
#include <iostream>
#include <fstream> 
#include <algorithm> // for lower_bound, upper_bound and sort
#include <vector>

// class data
// {
// private:
// 	std::string date;
// 	float value;
// };

class BitcoinExchange
{
private:
	std::vector<int> v;

public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange &src);
	~BitcoinExchange();
};
	