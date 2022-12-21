/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:42:34 by yhachami          #+#    #+#             */
/*   Updated: 2022/05/19 17:43:10 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	swap(int *x, int *y)
{
	int	t;

	t = *x;
	*x = *y;
	*y = t;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i +1;
		while (j < size)
		{
			if (tab[j] < tab[min])
				min = j;
			j++;
		}
		swap(&tab[min], &tab[i]);
		i++;
	}
}
