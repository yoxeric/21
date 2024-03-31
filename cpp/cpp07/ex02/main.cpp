
#include "Array.hpp"
#define MAX_VAL 750

// int * a = new int(); then display *a.

int main(int ac, char **av)
{
    Array< int > ar1;
    Array< int > ar2( 10 );
    Array< int > ar3( ar2 );

    std::cout << ar1[0] << std::endl;
    std::cout << ar1.size() << std::endl;

    std::cout << ar2[0] << std::endl;
    std::cout << ar2[1] << std::endl;
    std::cout << ar2[2] << std::endl;
    std::cout << ar2.size() << std::endl;

    ar2[0] += 1;
    std::cout << ar2[0] << std::endl;

    std::cout << ar3[0] << std::endl;
    std::cout << ar3[1] << std::endl;
    std::cout << ar3[2] << std::endl;
    std::cout << ar3.size() << std::endl;

    ar3[0] += 1;
    std::cout << ar3[0] << std::endl;
    std::cout << ar2[0] << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}