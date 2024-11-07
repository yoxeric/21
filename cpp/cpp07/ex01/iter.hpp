
#include <iostream>

template <typename T>
void    iter(T *a, int l, void (*f)(T&))
{
    for (int x = 0; x < l, x++)
    {
        (*f)(a[x]);
        f(a[x]);
    }
}

