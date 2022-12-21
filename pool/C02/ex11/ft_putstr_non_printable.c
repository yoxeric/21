/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:39:02 by yhachami          #+#    #+#             */
/*   Updated: 2022/05/25 04:51:15 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	prtchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			prtchar('\\');
			prtchar(hex[str[i] / 16]);
			prtchar(hex[str[i] % 16]);
		}
		else
		{
			prtchar(str[i]);
		}
		i++;
	}
}
