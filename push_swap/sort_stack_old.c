
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
