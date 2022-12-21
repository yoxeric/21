/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:50:41 by yhachami          #+#    #+#             */
/*   Updated: 2022/10/14 20:45:59 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	if (!s)
		return (0);
	new = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new)
		return (0);
	i = 0;
	while (s[i])
	{
		new[i] = f(i,*(char *) s + i);
		i++;
	}
	new[i] = '\0';
	return (new);
}
