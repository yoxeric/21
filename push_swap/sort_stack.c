/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:03:04 by yhachami          #+#    #+#             */
/*   Updated: 2023/04/02 11:56:58 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_three(t_stack *stk)
{
	int	big;

	big = get_biggest(stk->items, stk->top);
	if (big == 2)
		rotate(stk, "ra\n");
	else if (big != 0)
		reverse_rotate(stk, "rra\n");
	if (stk->items[stk->top] > stk->items[stk->top -1])
		swap(stk, "sa\n");
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	x;
	int	small;

	x = stack_a->top + 1;
	while (--x >= 3)
	{
		small = get_smallest(stack_a->items, stack_a->top);
		if (small > stack_a->top / 2)
			while (++small <= stack_a->top)
				rotate(stack_a, "ra\n");
		else
			while (--small >= -1)
				reverse_rotate(stack_a, "rra\n");
		push(stack_b, stack_a, "pb\n");
	}
	sort_three(stack_a);
	x = stack_a->size;
	while (--x >= 3)
		push(stack_a, stack_b, "pa\n");
}

void	sort_2k(t_stack *stack_a, t_stack *stack_b, int *nbrs, int chunk_size)
{
	int	chunk_start;

	chunk_start = 0;
	while (stack_a->top >= 0)
	{
		if (beef_chunk(stack_a, nbrs, chunk_start))
		{
			push(stack_b, stack_a, "pb\n");
			rotate(stack_b, "rb\n");
			chunk_start++;
		}
		else if (in_chunk(stack_a, nbrs, chunk_start, chunk_size))
		{
			push(stack_b, stack_a, "pb\n");
			chunk_start++;
		}
		else
			rotate(stack_a, "ra\n");
	}
}

void	sort_all(t_stack *stack_a, t_stack *stack_b, int *nbrs)
{
	int	chunk_size;
	int	big;

	chunk_size = 4;
	if (stack_a->size >= 10)
		chunk_size = stack_a->size / 4;
	if (stack_a->size >= 50)
		chunk_size = stack_a->size / 7;
	if (stack_a->size >= 200)
		chunk_size = stack_a->size / 13;
	if (stack_a->size >= 500)
		chunk_size = stack_a->size / 17;
	sort_2k(stack_a, stack_b, nbrs, chunk_size);
	while (stack_b->top >= 0)
	{
		big = get_biggest(stack_b->items, stack_b->top);
		if (big >= stack_b->top / 2)
			while (++big <= stack_b->top)
				rotate(stack_b, "rb\n");
		else
			while (--big >= -1)
				reverse_rotate(stack_b, "rrb\n");
		push(stack_a, stack_b, "pa\n");
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int *nbrs)
{
	if (stack_a->size == 2)
		if (stack_a->items[0] < stack_a->items[1])
			swap(stack_a, "sa\n");
	if (stack_a->size == 3)
		sort_three(stack_a);
	if (stack_a->size == 5 || stack_a->size == 4)
		sort_five(stack_a, stack_b);
	if (stack_a->size > 5)
		sort_all(stack_a, stack_b, nbrs);
}
