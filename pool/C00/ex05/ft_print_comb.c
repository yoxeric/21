/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 06:17:45 by yhachami          #+#    #+#             */
/*   Updated: 2022/05/18 15:31:21 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	prt3(int i, int j, int k)
{
	char	c;

	c = i + '0';
	write(1, &c, 1);
	c = j + '0';
	write(1, &c, 1);
	c = k + '0';
	write(1, &c, 1);
	if (i != 7)
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				prt3(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
