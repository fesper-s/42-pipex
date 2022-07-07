/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:30:15 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/25 11:14:16 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*tempnext;

	if (!*lst)
		return ;
	temp = *lst;
	while (temp)
	{
		tempnext = temp->next;
		ft_lstdelone(temp, del);
		temp = tempnext;
	}
	*lst = 0;
}
