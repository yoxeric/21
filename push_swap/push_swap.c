/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:41:09 by yhachami          #+#    #+#             */
/*   Updated: 2023/03/20 01:58:54 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ft_exit(int id)
{
	// if (id == -1)
	// 	write(2, "input erreur\n", 13);
	// else if (id == -2)
	// 	write(2, "numbre twice\n", 13);
	if (id < 0)
		write(2, "Error\n", 6);
	exit(1);
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

void	sort_nbrs(int *nbrs, int size)
{
	int	x;
	int	y;
	int	tmp;

	x = -1;
	while (++x < size - 1)
	{
		y = -1;
		while (++y < size - x - 1)
		{
			if (nbrs[y] > nbrs[y + 1])
			{
				tmp = nbrs[y + 1];
				nbrs[y + 1] = nbrs[y];
				nbrs[y] = tmp;
			}
		}
	}
	// x = size;
	// while (--x >= 0)
	// 	ft_printf("n[%d] %d \n", x, nbrs[x]);
	// ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*nbrs;

	if (ac >= 2)
	{
		nbrs = get_stack(av, &stack_a, &stack_b);
		sort_nbrs(nbrs, stack_a.size);
		sort_stack(&stack_a, &stack_b, nbrs);
		free(stack_a.items);
		free(stack_b.items);
		free(nbrs);
	}
	else
		write(2, "stack empty \n", 13);
	return (0);
}
