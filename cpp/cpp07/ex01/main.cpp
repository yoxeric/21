
#include"iter.hpp"

void funk(int &i)
{
    i++;
}

void punk(int *i)
{
    std::cout << *i << std::endl;
}

int main()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ::iter(a, 10, &funk);
    for (int x = 0; x < 10; x++)
    {
        std::cout << a[x] << std::endl;
        //punk(a[x]);
    }    
}