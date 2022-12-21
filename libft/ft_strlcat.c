/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:25:56 by yhachami          #+#    #+#             */
/*   Updated: 2022/10/14 21:00:40 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		dstlen;
	int		srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	dst += dstlen;
	srclen = ft_strlen(src);
	if (dstlen >= size || !src)
		return (srclen + size);
	i = dstlen;
	while (*src && i++ < size - 1)
		*dst++ = *src++;
	*dst = '\0';
	dst -= (i + 1);
	return (dstlen + srclen);
}
