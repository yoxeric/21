

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template<typename T>
int easyfind(T &container, int x)
{
    if (std::find(container.begin(), container.end(), x) != container.end())
    {
        std::cout << "found." << std::endl;
        return 0;
    }
    else
    {
        std::cout << "not found." << std::endl;
        return 1;
    }
}