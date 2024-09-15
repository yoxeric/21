
#include "RPN.hpp"

// int is_operation(char c)
// {
//     if (c == '+' || c == '-' || c == '*' || c == '/')
//         return 1;
//     return 0;
// }

// int    RPN::read_numbres(int ac, char **av)
// {
//     for (int i = 1; i < ac; i++)
//     {
//         std::string agv = std::string(av[i]);
//         size_t pos = agv.find(' ');
//         size_t start = 0;
//         std::string str;

//         while ( pos != std::string::npos )
//         {
//             str = agv.substr(start, pos - start);
//             // std::cout << "error: input " << i << " (" << str << ") " << str.size() << std::endl;
//             if (str.size() > 1)
//             {
//                 std::cout << "error: input " << i << " " << str << std::endl;
//                 return (0);
//             }
//             std::cout << "str = " << str[0] << std::endl;
//             all.push(str[0]);

//             start = pos + 1;
//             pos = agv.find(' ', start);
//         }
//         str = agv.substr(start, agv.size() - 1);
//         // std::cout << "error: input " << i << " (" << str << ") " << str.size() << std::endl;
//         if (str.size() > 1)
//         {
//             std::cout << "error: input " << i << " " << str << std::endl;
//             return (0);
//         }
//         std::cout << "str = " << str[0] << std::endl;
//         all.push(str[0]);
//     }
//     return (1);

// }

// int    RPN::split_numbres_and_operation()
// {
//     while (!all.empty())
//     {
//         if (is_operation(all.top()))
//             ops.push(all.top());
//         else if (isdigit(all.top()))
//             nbs.push(all.top() - '0');
//         else
//         {
//             std::cout << "error: nbop " << all.top() << std::endl;
//         }
//         all.pop();
//     }

//             std::cout << "size " << nbs.size() << " " << ops.size() << std::endl;
//     if (nbs.size() - 1 > ops.size())
//     {
//         std::cout << "error: need more operations " << std::endl;
//     	return (0);
//     }
//     else if (nbs.size() - 1 < ops.size())
//     {
//         std::cout << "error: need more numbres " << std::endl;
//     	return (0);
//     }
//     return (1);
// }

// void    RPN::execute_operation()
// {
//     while (!ops.empty())
//     {
//         int x = nbs.top();
//         std::cout << "nb x = " << nbs.top() << std::endl;
//         nbs.pop();
//         int y = nbs.top();
//         std::cout << "nb y = " << nbs.top() << std::endl;
//         nbs.pop();
//         int z = 0;
//         char op = ops.top();
//         std::cout << "op = " << ops.top() << std::endl;
//         if (op == '+')
//             z = x + y;
//         else if (op == '-')
//             z = x - y;
//         else if (op == '*')
//             z = x * y;
//         else if (op == '/')
//             z = x / y;
//         std::cout << "z = " << z << std::endl;
//         ops.pop();
//         nbs.push(z);
//     }
//     std::cout << "res = " << nbs.top() << std::endl;
// }