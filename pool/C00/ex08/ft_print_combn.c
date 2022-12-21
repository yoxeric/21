/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:20:07 by yhachami          #+#    #+#             */
/*   Updated: 2022/05/21 12:43:31 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	initab(int x[], int n)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		x[i] = i;
		i++;
	}
	x[n] = 11;
}

void	print_and_add(int x[], int n,	int k)
{
	char	c;
	int		i;

	while (x[k] < x[k +1] -1)
	{
		i = 0;
		while (i < n)
		{
			c = x[i] + '0';
			write(1, &c, 1);
			i++;
		}
		if (x[0] != 10 - n)
		{
			write(1, ",", 1);
			write(1, " ", 1);
		}
		x[k]++;
	}
}

void	ft_print_combn(int n)
{
	int	x[10];
	int	k;

	initab(x, n);
	k = n -1;
	while (k >= 0)
	{
		while (x[k] < x[k +1] && k < n -1)
		{
			k++;
			x[k] = x[k -1] +1;
		}
		print_and_add(x, n, k);
		while (x[k] == x[k +1] -1)
		{
			k--;
		}
		x[k]++;
	}
}
