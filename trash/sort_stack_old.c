
#include"push_swap.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (i < 500)
	{
		if (stack_a->top == stack_a->size -1)
		{
			printf("--------check--------- \n");
			j = 1;
			while (j <= stack_a->top)
			{
				if (stack_a->items[j -1] < stack_a->items[j])
					break ;
				if (j == stack_a->size -1)
				{
					printf("--------done--------- %d\n", i);
					print_stack(stack_a, stack_b);
					return ;
				}
				j++;
			}
		}
		if (stack_a->items[stack_a->top] > stack_a->items[stack_a->top -1])
			swap_a(stack_a);
		else if (x == -1)
		{
			x = 0;
			reverse_rotate_a(stack_a);
		}
		else if (stack_a->top <= 1)// stack_b->top)
		{
			while (stack_a->top < stack_a->size -1)
				push_a(stack_a, stack_b);
			x = -1;
		}
		else if (stack_a->items[stack_a->top] > stack_b->items[stack_b->top])
			push_b(stack_a, stack_b);
		else
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
		}
		//printf("%d",stack_a->top);
		i++;
		print_stack(stack_a, stack_b);
	}
	printf("--------failed---------\n");
	//while (stack_a->top < stack_a->size -1)
	//	push_a(stack_a, stack_b);
	// swap_a(&stack_a);
	// print_stack(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// print_stack(&stack_a, &stack_b);
	// double_rotate(&stack_a, &stack_b);
	// print_stack(&stack_a, &stack_b);
	// double_reverse_rotate(&stack_a, &stack_b);
	// print_stack(&stack_a, &stack_b);
	// swap_a(&stack_a);
	// print_stack(&stack_a, &stack_b);
	// push_a(&stack_a, &stack_b);
	// push_a(&stack_a, &stack_b);
	// push_a(&stack_a, &stack_b);
	// print_stack(&stack_a, &stack_b);
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

// void	sort_three(t_stack *stack_a, int *nbrs)
// {
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
// }

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