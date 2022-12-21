/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:10:39 by yhachami          #+#    #+#             */
/*   Updated: 2022/10/13 12:58:25 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*save;
	int		i;

	save = (char *) 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			save = (char *) &s[i];
		i++;
	}
	if (s[i] == (unsigned char) c)
		save = (char *) &s[i];
	return (save);
}
