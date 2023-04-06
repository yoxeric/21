/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:41:09 by yhachami          #+#    #+#             */
/*   Updated: 2023/04/02 12:05:40 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_double_exit(char **st)
{
	int	i;

	write(2, "Error\n", 6);
	i = -1;
	while (st[++i])
		free(st[i]);
	free(st);
	exit(1);
}

void	ft_exit(char *st)
{
	write(2, "Error\n", 6);
	free(st);
	exit(1);
}

int	check_stack(t_stack *stack_a)
{
	int	i;
	int	size;

	size = stack_a->size - 1;
	i = 0;
	while (i < size)
	{
		if (stack_a->items[i] < stack_a->items[i + 1])
			return (0);
		i++;
	}
	return (1);
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
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*nbrs;

	if (ac >= 2)
	{
		if (!(av[1][0]))
			return (0);
		nbrs = get_stack(av, &stack_a, &stack_b);
		sort_nbrs(nbrs, stack_a.size);
		if (!check_stack(&stack_a))
			sort_stack(&stack_a, &stack_b, nbrs);
		free(stack_a.items);
		free(stack_b.items);
		free(nbrs);
	}
	return (0);
}
