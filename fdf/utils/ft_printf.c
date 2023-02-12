//#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdarg.h>

int    ft_putchar(char c) 
{ 
        write(1,&c,1);
		return (1);
} 
 

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1,&str[i],1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long int nb;
	int digits;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		digits++;
		ft_putchar(nb + 48);
	}
	return (digits);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int res;
	char	*buffer;
	va_list	args;

	i = 0;
	va_start(args,s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
                res += ft_putchar('%');
			if (s[i + 1] == 'c')
				res += ft_putchar(va_arg(args, int));
			if (s[i + 1] == 's')
				res += ft_putstr(va_arg(args, char *));
			if (s[i + 1] == 'd')
                res += ft_putnbr(va_arg(args, double));
			if (s[i + 1] == 'i')
                res += ft_putnbr(va_arg(args, int));
			if (s[i + 1] == 'u')
                res += ft_putnbr(va_arg(args, long double));
			if (s[i + 1] == 'p')
				res += ft_putstr(va_arg(args, void *));
            if (s[i + 1] == 'x')
                res += ft_putstr(va_arg(args, char *));
			if (s[i + 1] == 'X')
                res += ft_putstr(va_arg(args, char *));
			i++;

		}
		else 
			res += ft_putchar((char)s[i]);
		i++;
	}
	//buffer = va_arg(args, char*);
	va_end(args);
	return (res);
}

int main()
{
	char c = '-';
	char *s = "this is official";
	int x = 71;
	float y = 132;
	double z = 3164.285;
	void *p;

	ft_printf("HeLLO world %% %s %c %i %d %u %p \n",s,c,x,y,z,p);
}
