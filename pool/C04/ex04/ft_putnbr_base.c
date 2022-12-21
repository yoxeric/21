/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:35:27 by yhachami          #+#    #+#             */
/*   Updated: 2022/05/26 00:12:24 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

int	ft_erreur(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
	{
		j = i;
		while (base[j] != '\0')
		{
			j++;
			if (base[i] == base[j])
				return (1);
		}
		if (base[i] == '+' || base[i] == '-' || base[i] < 33 || base[i] > 126)
			return (1);
		else
			i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	baselen;
	int	x;

	i = 0;
	baselen = 0;
	x = nbr;
	if (ft_erreur(base) == 0)
	{
		if (x < 0)
		{
			write(1, "-", 1);
			x *= -1;
		}
		while (base[baselen])
			baselen++;
		if (x < baselen)
			write(1, &base[x], 1);
		if (x >= baselen)
		{
			ft_putnbr_base(x / baselen, base);
			ft_putnbr_base(x % baselen, base);
		}
	}
}
