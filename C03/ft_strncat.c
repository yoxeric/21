/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 07:26:01 by yhachami          #+#    #+#             */
/*   Updated: 2022/05/21 16:25:37 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*dest != '\0')
	{
		dest++;
		i++;
	}
	while (*src != '\0' && (unsigned) j < nb)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
		j++;
	}
	*dest = '\0';
	dest -= i;
	return (dest);
}
