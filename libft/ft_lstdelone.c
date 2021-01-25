/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:38:20 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/17 16:38:23 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** void ft_lstdelone(t_list *lst, void (*del)(void *));
**
** [PARAMETER]
** #1. The element to free.
** #2. The address of the function used to delete the content.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if ((lst == NULL) || (del == NULL))
		return ;
	del(lst->content);
	free(lst);
}
