/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:03:04 by yhachami          #+#    #+#             */
/*   Updated: 2023/03/28 23:03:08 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	check_stack(t_stack *stack_a ,t_stack *stack_b)
{
	int	i;
	int	j;
	int	size;

	size = stack_a->size;
	i = 0;
	while (i < size - 1)
	{
		ft_printf("--------check--------- \n");
		j = 0;
		while (j <= size - 1)
		{
			if (stack_a->items[j] < stack_a->items[j + 1])
				break ;
			if (j == stack_a->size -1)
			{
				ft_printf("--------done--------- %d\n", i);
				print_stack(stack_a, stack_b);
				return ;
			}
			j++;
		}
		i++;
	}
	ft_printf("--------failed---------\n");
}

// sorted
//	> > >
// 3 2 1

// unsorted
//	< < <
// 1 2 3

//	< > <
// 1 3 2

//	> < <
// 2 1 3

//	< > >
// 2 3 1

//	> < >
// 3 1 2

	// if (nbrs[0] < nbrs[1] && nbrs[1] < nbrs[2] && nbrs[0] < nbrs[2])
	// {
	// 	swap(stack_a, "sa\n");
	// 	reverse_rotate(stack_a, "rra\n");
	// }
	// if (nbrs[0] < nbrs[1] && nbrs[1] > nbrs[2] && nbrs[0] < nbrs[2])
	// 	reverse_rotate(stack_a, "rra\n");
	// if (nbrs[0] > nbrs[1] && nbrs[1] < nbrs[2] && nbrs[0] < nbrs[2])
	// 	rotate(stack_a, "ra\n");
	// if (nbrs[0] < nbrs[1] && nbrs[1] > nbrs[2] && nbrs[0] > nbrs[2])
	// {
	// 	swap(stack_a, "sa\n");
	// 	rotate(stack_a, "ra\n");
	// }
	// if (nbrs[0] > nbrs[1] && nbrs[1] < nbrs[2] && nbrs[0] > nbrs[2])
	// 	swap(stack_a, "sa\n");

int	find_in_stack(t_stack *stk, int nb)
{
	int	x;

	x = stk->top + 1;
	while (--x >= 0)
		if (stk->items[x] == nb)
			return (x);
	return (-1);
}

int	get_biggest(int *nbrs, int size)
{
	int	x;
	int	big;

	x = -1;
	big = 0;
	while (++x <= size)
	{
		if(nbrs[x] > nbrs[big])
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
		if(nbrs[x] < nbrs[small])
			small = x;
	}
	return (small);
}

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
		// small = find_in_stack(stack_a, nbrs[x]);
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

// int	find_from_top(t_stack *stk, int *chk, int chunk_start, int chunk_size)
// {
// 	int	x;
// 	int	y;
// 	int	chk_limit;

// 	x = stk->top;
// 	while (--x >= -1)
// 	{
// 		y = stk->size - chunk_start;
// 		chk_limit = stk->size - chunk_start - chunk_size;
// 		if (chk_limit < 0)
// 			chk_limit = 0;
// 		while (--y >= chk_limit)
// 			if (stk->items[x] == chk[y])
// 				return (x);
// 	}
// 	return (stk->size + 1);
// }

// int	find_from_bot(t_stack *stk, int *chk, int chunk_start, int chunk_size)
// {
// 	int	x;
// 	int	y;
// 	int	chk_limit;

// 	x = -1;
// 	while (++x <= stk->top)
// 	{
// 		y = stk->size - chunk_start;
// 		chk_limit = stk->size - chunk_start - chunk_size;
// 		if (chk_limit < 0)
// 			chk_limit = 0;
// 		while (--y >= chk_limit)
// 			if (stk->items[x] == chk[y])
// 				return (x);
// 	}
// 	return (stk->size + 1);
// }

// int	find_smallest(t_stack *stk, int *chk, int chunk_size)
// {
// 	int	smallest;
// 	int	smallest2;

// 	smallest = find_from_top(stk, chk, 0, chunk_size);
// 	smallest2 = find_from_bot(stk, chk, 0, chunk_size);
// 	if (smallest < smallest2)
// 		return (smallest);
// 	else
// 		return (smallest2);
// }

// void	sort_all(t_stack *stack_a, t_stack *stack_b, int *nbrs)
// {
// 	int chunk_size;
// 	int	chunk_start;
// 	int	x;
// 	int	y;
// 	int	small;
// 	int	small2;
// 	int	smallest;
// 	int	big;

// 	chunk_size = 3;
// 	chunk_start = 1;
// 	big = 0;
// 	y = 0;
// 	x = stack_a->top + 1;
// 	while (--x >= 3)
// 	{
// 		small = find_from_top(stack_a, nbrs, chunk_start, chunk_size);
// 		small2 = find_from_bot(stack_a, nbrs, chunk_start, chunk_size);
// 		smallest = find_smallest(stack_a, nbrs, chunk_size);
// 		// ft_printf("x=%d, s1=%d, s2=%d, s3=%d, half=%d\n",x,small,small2, smallest,stack_a->top / 2);
// 		if (smallest <= small2 && smallest <= small)
// 		{
// 			big = 1;
// 			small = smallest;
// 		}
// 		else if (small2 <= small && small2 <= smallest)
// 			small = small2;
// 		if (small > stack_a->top / 2)
// 			while (++small <= stack_a->top)
// 				rotate(stack_a, "ra\n");
// 		else
// 			while (--small >= -1)
// 				reverse_rotate(stack_a, "rra\n");
// 		push(stack_b, stack_a, "pb\n");
// 		if (big == 1)
// 		{
// 			rotate(stack_b, "rb\n");
// 			big = 0;
// 		}
// 		y++;
// 		if (y >= 2)
// 		{
// 			y = 0;
// 			chunk_start++;
// 		// print_stack(stack_a, stack_b);
// 		}
// 	}
// 	sort_three(stack_a);
// 	x = stack_b->top;
// 	while (--x >= -1)
// 	{
// 		big = get_biggest(stack_b->items, stack_b->top);
// 		if (big > stack_a->top / 2)
// 			while (++big <= stack_a->top)
// 				rotate(stack_b, "rb\n");
// 		else
// 			while (--big >= -1)
// 				reverse_rotate(stack_b, "rrb\n");
// 		push(stack_a, stack_b, "pa\n");
// 	}
// 	sort_five(stack_a, stack_b);
// }

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

void	sort_all(t_stack *stack_a, t_stack *stack_b, int *nbrs)
{
	int	chunk_start;
	int	chunk_size;
	int big;

	chunk_start = 0;
	if (stack_a->size >= 10)
		chunk_size = stack_a->size / 10;
	else if (stack_a->size >= 50)
		chunk_size = stack_a->size / 13;
	else if (stack_a->size >= 500)
		chunk_size = stack_a->size / 17;
	while (stack_a->top >= 0)
	{
		if (beef_chunk(stack_a, nbrs, chunk_start))
		{
			push(stack_b, stack_a, "pb\n");
			// double_rotate(stack_a,stack_b);
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
	while (stack_b->top >= 0)
	{
		big = get_biggest(stack_b->items, stack_b->top);
		if (big >= stack_b->top / 2)
			while(++big <= stack_b->top)
				rotate(stack_b, "rb\n");
		else
			while(--big >= -1)
				reverse_rotate(stack_b, "rb\n");
		push(stack_a, stack_b, "pa\n");
	}
	// sort_five(stack_a, stack_b);
	// while (stack_b->top >= 5)
	// {
	// 	big = get_biggest(stack_b->items, stack_b->top);
	// 	if (big >= stack_b->top / 2)
	// 		while(++big <= stack_b->top)
	// 			rotate(stack_b, "rb\n");
	// 	else
	// 		while(--big >= -1)
	// 			reverse_rotate(stack_b, "rb\n");
	// 	push(stack_a, stack_b, "pa\n");
	// }
	print_stack(stack_a, stack_b);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int *nbrs)
{
	int	i;
	int	j;
	int	x;

	// print_stack(&stack_a, &stack_b);
	i = 0;
	j = 0;
	x = 0;
	if (stack_a->size == 2)
		if (nbrs[0] < nbrs[1])
			swap(stack_a, "sa\n");
	if (stack_a->size == 3)
		sort_three(stack_a);
	if (stack_a->size == 5 || stack_a->size == 4)
		sort_five(stack_a, stack_b);
	if (stack_a->size > 5)
		sort_all(stack_a, stack_b, nbrs);
	// ft_printf("\n");
	// print_stack(stack_a, stack_b);
}
