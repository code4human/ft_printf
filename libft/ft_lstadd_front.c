/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:37:07 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/17 16:37:10 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** void	ft_lstadd_front(t_list **lst, t_list *new);
**
** [PARAMETER]
** #1. The address of a pointer to the first link of a list.
** #2. The address of a pointer to the element to be added to the list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if ((lst == NULL) || (new == NULL))
		return ;
	new->next = *lst;
	*lst = new;
}
