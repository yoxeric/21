/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:52:06 by yhachami          #+#    #+#             */
/*   Updated: 2022/10/13 15:52:48 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	if (count >= SIZE_MAX && size >= SIZE_MAX)
		return (0);
	p = (char *) malloc(count * size);
	if (p != NULL)
		ft_bzero(p, count * size);
	return (p);
}
