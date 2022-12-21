/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:29:43 by yhachami          #+#    #+#             */
/*   Updated: 2022/10/07 16:19:49 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	while (i++ < size && *dst)
		dst++;
	dstlen = i;
	srclen = ft_strlen((char *)src);
	if (dstlen > size || size == 0)
		return (srclen + size);
	while (i++ <= size - 1 && *src)
	{
		*dst++ = *src;
		src++;
	}
	*dst = '\0';
	return (dstlen + srclen - 1);
}
