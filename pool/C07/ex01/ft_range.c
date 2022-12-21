/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 01:32:05 by yhachami          #+#    #+#             */
/*   Updated: 2022/06/02 21:58:42 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	range;
	int	*s;

	range = max - min;
	if (max <= min)
		return (0);
	s = (int *)malloc(sizeof(int) * range);
	i = 0;
	while (i < range)
	{
		s[i] = min + i;
		i++;
	}
	return (s);
}
