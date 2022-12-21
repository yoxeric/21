/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:44:15 by yhachami          #+#    #+#             */
/*   Updated: 2022/12/21 17:06:23 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nb, char *base)
{
	int				digits;
	unsigned int	baselen;

	digits = 0;
	baselen = 0;
	if (nb < 0)
	{
		digits += ft_putchar('-');
		nb *= -1;
	}
	while (base[baselen])
		baselen++;
	if (nb < baselen)
		digits += ft_putchar(base[nb]);
	else
	{
		digits += ft_putnbr_base(nb / baselen, base);
		digits += ft_putnbr_base(nb % baselen, base);
	}
	return (digits);
}
