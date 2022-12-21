/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:05:35 by yhachami          #+#    #+#             */
/*   Updated: 2022/10/16 22:06:52 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && word == 0)
			word = 1;
		else if ((s[i] == c || !s[i]) && word == 1)
		{
			word = 0;
			count++;
		}
		i++;
	}
	return (count +1);
}

static char	*split_word(char const *s, int *start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - *start + 1));
	if (!word)
		return (0);
	while (i < (end - *start) && s[i])
	{
		word[i] = s[*start + i];
		i++;
	}
	*start = -1;
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tbl;
	int		x;
	int		y;
	int		z;

	if (!s)
		return (0);
	tbl = malloc(count_words(s, c) * sizeof(char *));
	if (!tbl)
		return (0);
	x = 0;
	y = -1;
	z = 0;
	while (x <= ft_strlen(s))
	{
		if (y == -1 && s[x] != c)
			y = x;
		else if (y >= 0 && (s[x] == c || x == ft_strlen(s)))
			tbl[z++] = split_word(s, &y, x);
		x++;
	}
	tbl[z] = 0;
	return (tbl);
}

#include<stdio.h>

int main()
{
	char **s = ft_split("",'\0');
	int i = 0;
	while(s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
}
