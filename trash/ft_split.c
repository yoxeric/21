/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:08:35 by yhachami          #+#    #+#             */
/*   Updated: 2022/10/12 23:05:37 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_splits(char *s, char c, int len)
{
	int	count;
	int	i;
	int	word_start;

	word_start = -1;
	count = 0;
	i = 0;
	while (i <= len)
	{
		if (s[i] != c && word_start < 0)
			word_start = 1;
		else if ((s[i] == c || i == len) && word_start >= 0)
		{
			count++;
			word_start = -1;
		}
		i++;
	}
	return (count + 1);
}

char	*split_word(const char *str, int start, int finish)
{
	char	*word;
	int		len;

	len = finish - start + 1;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (0);
	ft_strlcpy(word, &str[start], len);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strtbl;
	int		x;
	int		y;
	int		z;

	if (!s)
		return (0);
	strtbl = malloc(count_splits((char *)s, c, ft_strlen(s)) * sizeof(char *));
	if (!strtbl)
		return (0);
	x = -1;
	y = 0;
	z = 0;
	while (y <= ft_strlen((char *)s))
	{
		if (x < 0 && s[y] != c)
			x = y;
		else if (x >= 0 && (s[y] == c || y == ft_strlen((char *)s)))
		{
			strtbl[z++] = split_word((char *)s, x, y);
			x = -1;
		}
		y++;
	}
	strtbl[z] = 0;
	return (strtbl);
}
