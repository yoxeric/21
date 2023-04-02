/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:53:27 by yhachami          #+#    #+#             */
/*   Updated: 2022/12/21 17:06:09 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nb)
{
	int	digits;

	digits = 0;
	if (nb < 16)
		digits += ft_putchar("0123456789abcdef"[nb]);
	else
	{
		digits += ft_puthex(nb / 16);
		digits += ft_puthex(nb % 16);
	}
	return (digits);
}
