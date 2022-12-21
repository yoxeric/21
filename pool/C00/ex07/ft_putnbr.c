/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:00:37 by yhachami          #+#    #+#             */
/*   Updated: 2022/05/19 07:36:03 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_length(int value)
{
	int	l;

	l = 0;
	while (value > 9)
	{
		l++;
		value /= 10;
	}
	return (l);
}

void	print_tbl(char n[], int len)
{
	int		i;
	char	c;

	i = 0;
	while (i <= len)
	{
		c = n[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int		i;
	int		digits;
	char	n[10];

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			write(1, "-", 1);
		}
		digits = get_length(nb);
		i = digits;
		while (nb)
		{
			n[i] = nb % 10;
			nb /= 10;
			i--;
		}
		print_tbl(n, digits);
	}
}
