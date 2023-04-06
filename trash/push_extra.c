
int	find_in_stack(t_stack *stk, int nb)
{
	int	x;

	x = stk->top + 1;
	while (--x >= 0)
		if (stk->items[x] == nb)
			return (x);
	return (-1);
}


void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_a->size -1;
	while (i >= 0)
	{
		ft_printf("[%d] ", i);
		if (i <= stack_a->top)
			ft_printf("%d  ", stack_a->items[i]);
		else
			ft_printf("   ");
		if (i <= stack_b->top)
			ft_printf("%d ", stack_b->items[i]);
		ft_printf("\n");
		i--;
	}
	ft_printf("    _   _\n    a   b\n");
}
