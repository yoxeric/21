/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 01:18:45 by yhachami          #+#    #+#             */
/*   Updated: 2022/10/11 03:37:07 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	int		i;

	if (!src && !dst)
		return (0);
	d = (char *)dst;
	s = (char *)src;
	i = n;
	if (d < s)
	{
		while (i--)
			*d++ = *s++;
	}
	else
	{
		d = (char *) dst + (i - 1);
		s = (char *) src + (i - 1);
		while (i--)
			*d-- = *s--;
	}
	return (dst);
}
