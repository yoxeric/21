/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:46:11 by yhachami          #+#    #+#             */
/*   Updated: 2022/12/21 18:41:58 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	get_arg(const char *s, va_list arg, int i);
int	ft_putchar(const char c);
int	ft_putstr(const char *s);
int	ft_putnbr(int nb);
int	ft_putnbr_base(unsigned int nb, char *base);
int	ft_putptr(void *p);
int	ft_puthex(unsigned long nb);

#endif
