/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:02:33 by yhachami          #+#    #+#             */
/*   Updated: 2022/10/13 05:24:23 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	srclen;

	s = (char *)src;
	srclen = ft_strlen(s);
	if (size > 0)
	{
		while (size-- > 1 && *s)
			*dst++ = *s++;
		*dst = '\0';
	}
	return (srclen);
}
