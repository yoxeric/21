/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:52:19 by yhachami          #+#    #+#             */
/*   Updated: 2022/12/21 17:06:34 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	digits;

	digits = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		digits += ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
		digits += ft_putchar(nb + '0');
	else
	{
		digits += ft_putnbr(nb / 10);
		digits += ft_putnbr(nb % 10);
	}
	return (digits);
}
