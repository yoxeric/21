#include<stdio.h>
#include<unistd.h>

int ft_strlen(char *str);
void ft_putstr(char *str);
void ft_putnbr(int nb);
int ft_atoi(char *str);
void ft_putnbr_base(int nbr, char *base);

int main()
{
	int a;
	char c;

	a = ft_strlen("short");
	c = a + '0';
	write(1,&c,1);

    write(1,"\n",1);
	ft_putstr("string");

    write(1,"\n",1);
	ft_putnbr(-2147483648);
    write(1,"\n",1);
    ft_putnbr(2147483647);

    write(1,"\n",1);
	a = ft_atoi("   --+---+++-+-+45615 af867");
	ft_putnbr(a);

    write(1,"\n",1);
	ft_putnbr_base(120,"01");
}
