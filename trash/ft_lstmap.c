/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:16:25 by yhachami          #+#    #+#             */
/*   Updated: 2022/10/11 10:06:41 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*result;

	if (!lst || !(*f) || !(*del))
		return (0);
	result = ft_lstnew(f(lst->content));
	current = result;
	lst = lst->next;
	while (lst)
	{
		current->next = ft_lstnew(f(lst->content));
		if (!(current->next))
			ft_lstclear(&result, del);
		current = current->next;
		lst = lst->next;
	}
	return (result);
}
