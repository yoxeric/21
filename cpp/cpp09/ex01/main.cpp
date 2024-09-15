

#include "RPN.hpp"

int is_operation(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

void    RPN::read_arg(std::string str)
{
    // std::cout << "input = " << i << " (" << str << ") " << str.size() << std::endl;
    if (str.size() > 1)
    {
        std::cout << "error: input " << str << std::endl;
        return ;
    }
    std::cout << "> " << str[0] << std::endl;
    if (is_operation(str[0]))
    {
        char op = str[0];

        // if ops exucute last 2 numbres
        if (nbs.size() >= 2)
            nbs.push( execute_operation(op) );
        else
            std::cout << "error: no nbs " << str[0] << std::endl;
    }
    else if (isdigit(str[0]))
        nbs.push((int) str[0] - '0');
}

int    RPN::read_numbres(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string arg = std::string(av[i]);
        size_t pos = arg.find(' ');
        size_t start = 0;
        while ( pos != std::string::npos )
        {
            // fill nbs and ops
            read_arg(arg.substr(start, pos - start));
            start = pos + 1;
            pos = arg.find(' ', start);
        }
        // std::cout << "error: input " << i << " (" << str << ") " << str.size() << std::endl;
        read_arg(arg.substr(start, arg.size() - 1));
    }
    std::cout << nbs.top() << std::endl;
    return (1);
}

int    RPN::execute_operation(char op)
{
    int y = nbs.top();
    nbs.pop();
    int x = nbs.top();
    nbs.pop();
    int z = 0;
    if (op == '+')
        z = x + y;
    else if (op == '-')
        z = x - y;
    else if (op == '*')
        z = x * y;
    else if (op == '/')
        z = x / y;
    std::cout << x << " " << op << " " << y << " = " << z << std::endl;
    return (z);
}

int main(int ac, char **av)
{
    RPN revpolinota;

    if (!revpolinota.read_numbres(ac, av))
        return (1);
    // if (!revpolinota.split_numbres_and_operation())
    //     return (1);
    // revpolinota.execute_operation();
    return (0);
}
