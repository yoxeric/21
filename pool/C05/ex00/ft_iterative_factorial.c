/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:56:59 by yhachami          #+#    #+#             */
/*   Updated: 2022/05/28 14:10:19 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	x;

	if (nb < 0)
		return (0);
	x = 1;
	while (nb > 0)
	{
		x *= nb;
		nb--;
	}
	return (x);
}