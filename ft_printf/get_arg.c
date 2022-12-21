/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:02:26 by yhachami          #+#    #+#             */
/*   Updated: 2022/12/21 18:42:31 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_arg(const char *s, va_list arg, int i)
{
	if (s[i] == '%')
		return (ft_putchar('%'));
	if (s[i] == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (s[i] == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (s[i] == 'i' || s[i] == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	if (s[i] == 'u')
		return (ft_putnbr_base(va_arg(arg, unsigned int), "0123456789"));
	if (s[i] == 'x')
		return (ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef"));
	if (s[i] == 'X')
		return (ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	if (s[i] == 'p')
		return (ft_putptr(va_arg(arg, void *)));
	return (0);
}
