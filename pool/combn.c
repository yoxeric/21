#include <unistd.h>

void	add_and_print(int x[], int n,	int k)
{
	char	c;
	int		i;

	while (x[k] <= x[k -1] -1)
	{
		i = n;
		while (i > 0)
		{
			c = x[i] + '0';
			write(1, &c, 1);
			i--;
		}
		if (x[n] != 10 - n)
		{
			write(1, ",", 1);
			write(1, " ", 1);
		}
		x[k]++;
	}
}

void	initab(int x[])
{
	int	i;

	i = 0;
	while (i < 9)
	{
		x[i] = 0;
		i++;
	}
	x[0] = 10;
}

void	ft_print_combn(int n)
{
	int	x[10];
	int	k;
	int	i;

	initab(x);
	k = 1;
	while (k <= n)
	{
		while (x[k] == x[k -1] -1)
		{
			x[k] = x[k +1] +1;
			k--;
		}
		x[k] = x[k +1] +1;
		add_and_print(x, n, k);
		while (x[k +1] == x[k] -1)
		{
			k++;
		}
		x[k +1]++;
		if (k == n)
			k++;
	}
}

