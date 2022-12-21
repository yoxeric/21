#include<stdio.h>

int ft_iterative_factorial(int nb);
int ft_recursive_factorial(int nb);
int ft_iterative_power(int nb, int power);
int ft_recursive_power(int nb, int power);
int ft_fibonacci(int index);
int ft_sqrt(int nb);
int ft_is_prime(int nb);
int ft_find_next_prime(int nb);

int main()
{
	int a;

	a = ft_iterative_factorial(7);
	printf("%d \n",a);
	
    a = ft_recursive_factorial(7);
    printf("%d \n",a);

    a = ft_iterative_power(0,0);
    printf("%d \n",a);

    a = ft_recursive_power(0,0);
    printf("%d \n",a);
		
	a = ft_fibonacci(7);
    printf("%d \n",a);

    a = ft_sqrt(2147395600);
    printf("%d \n",a);

    a = ft_is_prime(17);
    printf("%d \n",a);

    a = ft_find_next_prime(24);
    printf("%d \n",a);
}
