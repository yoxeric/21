
#include"easyfind.hpp"

int main(int ac, char **av)
{
    
    if (ac != 2)
    {
        std::cout << "usage: ./easyfind [numbre]" << std::endl;
        return 1;
    }

    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<int> vect(arr, arr + sizeof(arr) / sizeof(int));
    std::list<int> lst(arr, arr + sizeof(arr) / sizeof(int));

    easyfind(vect, av[1]);
    easyfind(lst, av[1]);

    return 0;
}