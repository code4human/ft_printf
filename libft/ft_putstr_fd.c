/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 06:19:30 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/13 06:39:10 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** void ft_putstr_fd(char *s, int fd);
*/

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

/*
**int	main(void)
**{
**	printf("====ft_putstr_fd====\n");
**	ft_putstr_fd("42Seoul", 1);
**	printf("\n");
**	ft_putstr_fd("Cadet", -1);
**	return (0);
**}
*/
