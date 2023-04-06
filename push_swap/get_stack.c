/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:45:21 by yhachami          #+#    #+#             */
/*   Updated: 2023/04/02 11:52:35 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	has_nbs(char *s)
{
	int		x;
	int		has_nb;

	has_nb = 0;
	x = -1;
	while (s[++x])
		if (s[x] >= '0' && s[x] <= '9')
			has_nb = 1;
	if (has_nb == 0)
		ft_exit(NULL);
}

int	count_nbrs(char **nb_st)
{
	int	n;
	int	i;
	int	j;

	i = -1;
	n = 0;
	while (nb_st[++i])
	{
		if ((nb_st[i][0] == '-' || nb_st[i][0] == '+')
			&& !(nb_st[i][1] >= '0' && nb_st[i][1] <= '9'))
			ft_double_exit(nb_st);
		if (!(nb_st[i][0] >= '0' && nb_st[i][0] <= '9')
			&& nb_st[i][0] != '-' && nb_st[i][0] != '+')
			ft_double_exit(nb_st);
		j = 0;
		while (nb_st[i][++j])
			if (!(nb_st[i][j] >= '0' && nb_st[i][j] <= '9'))
				ft_double_exit(nb_st);
		n++;
	}
	return (n);
}

int	*convert_nbrs(char **str, int size)
{
	int	*nbs;
	int	x;
	int	y;

	nbs = (int *) malloc(size * sizeof(int));
	y = size;
	x = -1;
	while (++x < size)
		nbs[--y] = ft_atoi(str[x]);
	if (size > 1)
	{
		x = -1;
		while (nbs[++x])
		{
			y = -1;
			while (nbs[++y])
			{
				if (x != y && nbs[x] == nbs[y])
					ft_double_exit(str);
			}
		}
	}
	return (nbs);
}

int	*fill_stack(int size)
{
	int	*nbs;
	int	i;

	nbs = (int *) malloc(size * sizeof(int));
	i = -1;
	while (++i < size)
		nbs[i] = 0;
	return (nbs);
}

int	*get_stack(char **av, t_stack *stack_a, t_stack *stack_b)
{
	char	**nb_st;
	int		*nbrs;
	int		i;

	i = 0;
	while (av[++i])
		has_nbs(av[i]);
	nb_st = ft_split(&av[1], ' ');
	stack_a->size = count_nbrs(nb_st);
	stack_b->size = stack_a->size;
	stack_a->top = stack_a->size - 1;
	stack_b->top = -1;
	stack_a->items = convert_nbrs(nb_st, stack_a->size);
	stack_b->items = fill_stack(stack_b->size);
	nbrs = convert_nbrs(nb_st, stack_a->size);
	i = -1;
	while (++i < stack_a->size)
		free(nb_st[i]);
	free(nb_st);
	return (nbrs);
}
