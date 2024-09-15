

#include <iostream>
#include <sstream> 
#include <stack>
#include <ctype.h> 

class RPN
{
    private:
        std::stack<int> nbs;

    public:
        int     read_numbres(int ac, char **av);
        void    read_arg(std::string str);
        // int    split_numbres_and_operation();
        // void    execute_operation();
        int    execute_operation(char op);
    
};
