/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:04:19 by yhachami          #+#    #+#             */
/*   Updated: 2022/05/25 04:40:53 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	getlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
	{
		l++;
	}
	return (l);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				source_size;

	if (!dest || !src)
		return (0);
	source_size = getlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (source_size);
}
