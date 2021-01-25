/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 06:19:15 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/13 06:08:00 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** void	ft_putchar_fd(char c, int fd);
*/

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

/*
**int	main(void)
**{
**	printf("====ft_putchar_fd====\n");
**	ft_putchar_fd('A', 1);
**	printf("\n");
**	ft_putchar_fd('a', -1);
**	return (0);
**}
*/
