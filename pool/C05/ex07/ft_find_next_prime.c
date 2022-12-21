/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 12:27:34 by yhachami          #+#    #+#             */
/*   Updated: 2022/05/28 14:16:40 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	primo(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (primo(nb))
		return (nb);
	else
	{
		while (primo(nb) == 0)
			nb++;
		return (nb);
	}
}
