 
 #include "BitcoinExchange.hpp"

 int main(int ac, char **av)
 {
 	if (ac != 2)
 	{
 		std::cout << "./btc [data file]" << std::endl;
        return (0);
 	}

 	BitcoinExchange btc;
    std::ifstream data("data.csv");
    std::ifstream txt(av[1]);

    std::string txt_line;
    while (std::getline(txt, txt_line))
    {
        // std::cout << "txt ----- " << txt_line << std::endl;

        std::string data_line;
        while (std::getline(data, data_line))
        {
            // std::cout << "data ----- " << data_line << std::endl;

            int txt_split = txt_line.find('|') - 1;
            int data_split = data_line.find(',');

            std::string txt_time = txt_line.substr(0, txt_split);
            std::string data_time = data_line.substr(0, data_split);

            // std::cout << txt_time << " =?= " << data_time << std::endl;
            if (txt_time == data_time)
            {
                // std::cout << "Match ----- "<< txt_time << " == " << data_time << std::endl;
                std::cout << txt_time;

                std::string txt_price = txt_line.substr(txt_split + 3);
                std::string data_price = data_line.substr(data_split + 1);

                float txt_money = std::atof(txt_price.c_str());
                float data_money = std::atof(data_price.c_str());

                std::cout << " => " << txt_price << " = " << txt_money * data_money << std::endl;
                // std::cout << "money $$$ ----- "<< txt_money * data_money << std::endl;

                break;
            }
        }
        data.clear();
        data.seekg(0);
    }
    return (1);
 }