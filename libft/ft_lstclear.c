/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:32:39 by yhachami          #+#    #+#             */
/*   Updated: 2022/10/12 22:38:28 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;
	t_list	*tmp;

	if (!lst || !(*del))
		return ;
	l = *lst;
	while (l)
	{
		tmp = l->next;
		del(l->content);
		free(l);
		l = tmp;
	}
	*lst = NULL;
}
