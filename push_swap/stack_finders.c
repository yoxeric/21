/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_finders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:49:12 by yhachami          #+#    #+#             */
/*   Updated: 2023/04/02 11:49:37 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	get_biggest(int *nbrs, int size)
{
	int	x;
	int	big;

	x = -1;
	big = 0;
	while (++x <= size)
	{
		if (nbrs[x] > nbrs[big])
			big = x;
	}
	return (big);
}

int	get_smallest(int *nbrs, int size)
{
	int	x;
	int	small;

	x = -1;
	small = 0;
	while (++x <= size)
	{
		if (nbrs[x] < nbrs[small])
			small = x;
	}
	return (small);
}

int	in_chunk(t_stack *stk, int *nbrs, int chunk_start, int chunk_size)
{
	int	x;

	x = chunk_start - 1;
	while (++x <= chunk_start + chunk_size)
	{
		if (nbrs[x] == stk->items[stk->top])
			return (1);
	}
	return (0);
}

int	beef_chunk(t_stack *stk, int *nbrs, int chunk_start)
{
	int	x;

	x = -1;
	while (++x <= chunk_start)
	{
		if (nbrs[x] == stk->items[stk->top])
			return (1);
	}
	return (0);
}
