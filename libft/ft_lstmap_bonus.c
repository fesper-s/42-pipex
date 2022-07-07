/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 07:44:51 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/27 10:13:03 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newcontent;

	if (!lst)
		return (0);
	newlst = 0;
	while (lst)
	{
		newcontent = ft_lstnew(f(lst->content));
		if (!newcontent)
			ft_lstclear(&newcontent, *del);
		else
			ft_lstadd_back(&newlst, newcontent);
		lst = lst->next;
	}
	return (newlst);
}
