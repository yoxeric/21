/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:19:45 by yhachami          #+#    #+#             */
/*   Updated: 2022/12/21 18:41:52 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
			res += get_arg(s, arg, ++i);
		else
			res += ft_putchar(s[i]);
		i++;
	}
	va_end(arg);
	return (res);
}
