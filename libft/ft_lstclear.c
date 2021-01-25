/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:38:30 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/17 17:20:59 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** void ft_lstclear(t_list **lst, void (*del)(void *));
**
** [PARAMETER]
** #1. The address of a pointer to an element.
** #2. The address of the function used to delete the content of the element.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;

	if ((lst == NULL) || (*lst == NULL) || (del == NULL))
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		*lst = curr->next;
		ft_lstdelone(curr, del);
		curr = *lst;
	}
}
