#include <stdio.h>
#include<unistd.h>

void ft_putchar(char c);
void ft_print_alphabet(void);
void ft_print_reverse_alphabet(void);
void ft_print_numbers(void);
void ft_is_negative(int n);
void ft_print_comb(void);
void ft_print_comb2(void);
void ft_putnbr(int nb);
void ft_print_combn(int n);


int main(){
	ft_putchar('a');
    write(1,"\n",1);
	ft_print_alphabet();
	write(1,"\n",1);
	ft_print_reverse_alphabet();
    write(1,"\n",1);
	ft_print_numbers();
    write(1,"\n",1);
    ft_is_negative(-42);
	ft_is_negative(0);
    ft_is_negative(42);
    write(1,"\n",1);
 	ft_print_comb();
    write(1,"\n",1);
	ft_print_comb2();
    write(1,"\n",1);
  	ft_putnbr(2147483647);
    ft_putnbr(-2147483648);
    write(1,"\n",1);
	ft_print_combn(5);
	return 0;
}
