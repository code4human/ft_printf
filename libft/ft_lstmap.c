/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:38:55 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/20 01:57:57 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
**
** [PARAMETER]
** #1. The address if a pointer to an element
** #2. The address of the function used to iterate on the list.
** #3. The address of the function used to delete the content
** of an element if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*curr;

	if ((lst == NULL) || (f == NULL))
		return (NULL);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		curr = ft_lstnew((*f)(lst->content));
		if (!curr)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, curr);
		lst = lst->next;
	}
	return (new);
}
