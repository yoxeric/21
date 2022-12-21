/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:53:43 by yhachami          #+#    #+#             */
/*   Updated: 2022/05/26 21:38:26 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(char **p1, char **p2)
{
	char	*temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

void	prt_params(char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < ac)
	{
		j = 1;
		while (j < ac)
		{
			if (compare(av[i], av[j]) < 0)
			{
				temp = av[i];
				av[i] = av[j];
				av[j] = temp;
			}
			j++;
		}
		i++;
	}
	prt_params(av);
}
