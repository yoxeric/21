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

#include "push_swap.h"

int	count_words(char *s, char c)
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
	return (count);
}

char	*split_word(char *s, int *start, int end)
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

int	split(char **tbl, char *s, char c)
{
	int		x;
	int		word_start;
	int		word_count;

	x = 0;
	word_start = -1;
	word_count = 0;
	while (x <= ft_strlen(s))
	{
		if (word_start == -1 && s[x] != c)
			word_start = x;
		else if (word_start >= 0 && (s[x] == c || x == ft_strlen(s)))
			tbl[word_count++] = split_word(s, &word_start, x);
		x++;
	}
	return (word_count);
}

char	**ft_split(char **s, char c)
{
	char	**tbl;
	int		x;
	int		size;
	int		word_count;

	if (!s)
		return (0);
	size = 1;
	x = -1;
	while (s[++x])
		size += count_words(s[x], c);
	tbl = (char **) malloc(size * sizeof(char *));
	if (!tbl)
		return (0);
	word_count = 0;
	x = -1;
	while (s[++x])
		word_count += split(&tbl[word_count], s[x], c);
	tbl[word_count] = 0;
	return (tbl);
}
