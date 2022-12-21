/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 02:23:13 by yhachami          #+#    #+#             */
/*   Updated: 2022/06/02 21:58:19 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;
	int	*rg;

	size = max - min;
	if (size <= 0)
	{
		*range = NULL;
		return (0);
	}
	rg = (int *)malloc(4 * size);
	if (!rg)
		return (-1);
	i = 0;
	while (i < size)
	{
		rg[i] = min + i;
		i++;
	}
	*range = rg;
	return (size);
}
