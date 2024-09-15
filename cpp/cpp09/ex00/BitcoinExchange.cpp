
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

int BitcoinExchange::register_data(std::string data)
{
    std::ifstream data_file(data);
    std::string data_line;

    for (int x = 0; std::getline(data_file, data_line); x++)
    {
        int data_split = data_line.find(',');

        std::string time = data_line.substr(0, data_split);
        // addTime(data_line.substr(0, data_split));

        float price = std::atof( data_line.substr(data_split + 1).c_str());
        // addPrice(std::atof( data_line.substr(data_split + 1).c_str()));

        map.insert(std::pair<std::string, float>(time, price));
        // std::cout << "data val ----- " << data.getPrice(x) << std::endl;
    }
    data_file.clear();
    data_file.seekg(0);
    return (1);
}

int BitcoinExchange::parse_time(std::string time)
{
    //Year-Month-Day
    int y,m,d;

    // std::cout << "T : ";
    size_t split = time.find('-');
    if (split != std::string::npos)
    {
        std::string year;
        for (size_t x = 0; x < split; x++)
        {
            year.push_back(time[x]);
            // std::cout << time[x];
            if (!isdigit(time[x]))
                return (0);
        }
        y = std::atoi(year.c_str());
    }
    else
        return 0;

    // std::cout << "   ";

    size_t split2 = time.find('-', split + 1);
    if (split != std::string::npos)
    {
        std::string month;
        for (size_t x = split + 1; x < split2; x++)
        {
            month.push_back(time[x]);
            if (!isdigit(time[x]))
                return (0);
        }
        // std::cout << month;
        m = std::atoi(month.c_str());
        if (m > 12)
            return 0;
    }
    else
        return 0;

    // std::cout << "   ";

    std::string day;
    for (size_t x = split2 + 1; x < time.size(); x++)
    {
        day.push_back(time[x]);
        if (!isdigit(time[x]))
            return (0);
    }
    // std::cout << day;
    d = std::atoi(day.c_str());
    if ((d > 31 && (m % 2) == 0) || (d > 30 && (m % 2) == 1) || (d > 29 && m == 2))
        return 0;

    // std::cout << std::endl;
    return 1;
}

int     BitcoinExchange::calculate_money(std::string txt)
{
    std::ifstream txt_file(txt);
    std::string txt_line;
    
    for (int x = 0; std::getline(txt_file, txt_line); x++)
    {
        // ---------  "date | value".
        size_t txt_split = txt_line.find('|') - 1;
        if (txt_split != std::string::npos)
        {
            // ---------  Year-Month-Day
            std::string time = txt_line.substr(0, txt_split);

            // --------- float or a positive integer, between 0 and 1000.
            std::string price_txt = txt_line.substr(txt_split + 3);

            float price = std::atof(price_txt.c_str());

            // std::cout << "txt val ----- " << time << " | " << price << std::endl;

            struct tm tm;
            // printf(" -------- y: %d | m: %d | d: %d;\n",
            //         tm.tm_year, tm.tm_mon, tm.tm_mday);

            if (parse_time(time) == 0)
            {
                std::cout << "Error : bad input = " << time << std::endl;
                continue ;
            }
            if (strptime(time.c_str(), "%Y-%m-%d", &tm) == NULL)
            {
                std::cout << "Error : bad input = " << time << std::endl;
                continue ;
            }
            if (price > 1000)
            {
                std::cout << "Error : price too big " << std::endl;
                continue ;
            }
            else if (price < 0)
            {
                std::cout << "Error : price too small " << std::endl;
                continue ;
            }

            std::cout << time;
            // std::cout << " => " << std::setprecision(10) << price;
            // std::cout << " * " << data.Time2Price(btc.getTime(i));
            std::cout << " => " << map[time] << " = " << price * map.lower_bound(time)->second << std::endl;

        }
        else
        {
            std::cout << "Error : line format = " << x << std::endl;
            return (0);
        }
    }
    return (1);
}

float  BitcoinExchange::Time2Price(std::string s)
{
    std::map<std::string, float>::iterator j = map.lower_bound(s);
    // // std::cout << *j << " == " << s << std::endl;
    if (j != map.end())
    {
        return (j->second);
    }
    return (0);

}

// float  BitcoinExchange::Time2Price(std::string s)
// {
//     std::vector<std::string>::iterator j = std::lower_bound(time.begin(), time.end(), s);
//     // std::cout << *j << " == " << s << std::endl;
//     if (j != time.end())
//     {
//         int index = std::distance(time.begin(), j);
//         return (price[index]);
//     }
//     return (0);
// }

// int     BitcoinExchange::getSize()
// {
//     return (time.size());
// }

// void	BitcoinExchange::addTime(std::string s)
// {
//     time.push_back(s);
// }
// void	BitcoinExchange::addPrice(float p)
// {
//     price.push_back(p);
// }

// void	BitcoinExchange::setTime(int index, std::string s)
// {
//     time[index] = s;
// }

// std::string	BitcoinExchange::getTime(int index)
// {
//     return (time[index]);
// }

// void	BitcoinExchange::setPrice(int index, float p)
// {
//     price[index] = p;
// }

// float	BitcoinExchange::getPrice(int index)
// {
//     return (price[index]);
// }
