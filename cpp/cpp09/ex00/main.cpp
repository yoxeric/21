 
 #include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "./btc [data file]" << std::endl;
        return (0);
    }

    BitcoinExchange data;

    data.register_data("data.csv");

    data.calculate_money(av[1]);


}

// int main(int ac, char **av)
// {
//     if (ac != 2)
//     {
//         std::cout << "./btc [data file]" << std::endl;
//         return (0);
//     }

//     std::ifstream data_file("data.csv");
//     std::ifstream txt_file(av[1]);

//     BitcoinExchange btc;
//     BitcoinExchange data;

//     std::string txt_line;

//     int x = 0;
//     while (std::getline(txt_file, txt_line))
//     {
//         // ---------  "date | value".
//         size_t txt_split = txt_line.find('|') - 1;
//         if (txt_split != std::string::npos)
//         {
//             // ---------  Year-Month-Day
//             std::string time_txt = txt_line.substr(0, txt_split);

//             btc.addTime(time_txt);

//             // --------- float or a positive integer, between 0 and 1000.
//             std::string price_txt = txt_line.substr(txt_split + 3);

//             float price = std::atof(price_txt.c_str());

//             btc.addPrice(price);
//             // std::cout << "txt val ----- " << btc.getTime(x) << " | " << btc.getPrice(x) << std::endl;
//         }
//         else
//         {
//             std::cout << "Error : line format = " << x << std::endl;
//         }
//         x++;
//     }

//     std::string data_line;
//     x = 0;
//     while (std::getline(data_file, data_line))
//     {
//         int data_split = data_line.find(',');

//         data.addTime(data_line.substr(0, data_split));

//         data.addPrice(std::atof( data_line.substr(data_split + 1).c_str()));
//         // std::cout << "data val ----- " << data.getPrice(x) << std::endl;
//         x++;
//     }
//     data_file.clear();
//     data_file.seekg(0);

//     for (int i = 1; i < btc.getSize(); i++)
//     {
//         std::string time = btc.getTime(i);
//         float price = btc.getPrice(i);

//         struct tm tm;
//         // printf(" -------- y: %d | m: %d | d: %d;\n",
//         //         tm.tm_year, tm.tm_mon, tm.tm_mday);

//         if (parse_time(time) == 0)
//         {
//             std::cout << "Error : time = " << time << std::endl;
//             continue ;
//         }
//         if (strptime(time.c_str(), "%Y-%m-%d", &tm) == NULL)
//         {
//             std::cout << "Error : str time = " << time << std::endl;
//             continue ;
//         }
//         if (price > 1000)
//         {
//             std::cout << "Error : price too big " << std::endl;
//             continue ;
//         }
//         else if (price < 0)
//         {
//             std::cout << "Error : price too small " << std::endl;
//             continue ;
//         }

//         std::cout << time;
//         std::cout << " => " << std::setprecision(10) << price;
//         // std::cout << " * " << data.Time2Price(btc.getTime(i));
//         std::cout << " = " << btc.getPrice(i) * data.Time2Price(btc.getTime(i)) << std::endl;
//     }

//     return (1);
// }

//  int main(int ac, char **av)
//  {
//  	if (ac != 2)
//  	{
//  		std::cout << "./btc [data file]" << std::endl;
//         return (0);
//  	}

//     std::ifstream data_file("data.csv");
//     std::ifstream txt_file(av[1]);

//     std::string txt_line;
//     while (std::getline(txt, txt_line))
//     {
//         // std::cout << "txt ----- " << txt_line << std::endl;

//         std::string data_line;
//         while (std::getline(data, data_line))
//         {
//             // std::cout << "data ----- " << data_line << std::endl;

//             int txt_split = txt_line.find('|') - 1;
//             int data_split = data_line.find(',');

//             std::string txt_time = txt_line.substr(0, txt_split);
//             std::string data_time = data_line.substr(0, data_split);

//             // std::cout << txt_time << " =?= " << data_time << std::endl;
//             if (txt_time == data_time)
//             {
//                 // std::cout << "Match ----- "<< txt_time << " == " << data_time << std::endl;
//                 std::cout << txt_time;

//                 std::string txt_price = txt_line.substr(txt_split + 3);
//                 std::string data_price = data_line.substr(data_split + 1);

//                 float txt_money = std::atof(txt_price.c_str());
//                 float data_money = std::atof(data_price.c_str());

//                 std::cout << " => " << txt_price << " = " << txt_money * data_money << std::endl;
//                 // std::cout << "money $$$ ----- "<< txt_money * data_money << std::endl;

//                 break;
//             }
//         }
//         data.clear();
//         data.seekg(0);
//     }
//  }
 