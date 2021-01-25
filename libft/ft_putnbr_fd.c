/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 06:20:23 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/13 06:41:02 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** void	ft_putnbr_fd(int n, int fd);
*/

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putnbr_fd(-2, fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

/*
**int	main(void)
**{
**	printf("====ft_putnbr_fd====\n");
**	printf("====MIN_OF_INT====\n");
**	ft_putnbr_fd(-2147483648, 1);
**	printf("\n====MAX_OF_INT====\n");
**	ft_putnbr_fd(2147483647, 1);
**	printf("\n");
**	return (0);
**}
*/
