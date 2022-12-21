/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 02:58:56 by yhachami          #+#    #+#             */
/*   Updated: 2022/06/02 20:02:19 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*dest != '\0')
	{
		i++;
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	dest -= i;
	return (dest);
}

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

int	joinedlen(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		if (i < size -1)
			len += ft_strlen(sep);
		i++;
	}
	len++;
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*s;
	int		len;

	if (size == 0)
	{
		s = malloc(1);
		*s = 0;
		return (s);
	}
	len = joinedlen(size, strs, sep);
	s = (char *)malloc(len);
	if (!s)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_strcat(s, strs[i]);
		if (i < size -1)
			ft_strcat(s, sep);
		i++;
	}
	return (s);
}
