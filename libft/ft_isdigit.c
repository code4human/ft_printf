/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:24:52 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/17 19:01:01 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** #include <ctype.h>
** int	isdigit(int c);
*/

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
**int 		main(void)
**{
**	printf("====ft_isdigit====\n");
**	printf("%d\n", ft_isdigit('4'));
**	printf("%d\n", ft_isdigit('A'));
**	printf("%d\n", ft_isdigit(42));
**	printf("====isdigit====\n");
**	printf("%d\n", isdigit('4'));
**	printf("%d\n", isdigit('A'));
**	printf("%d\n", isdigit(42));
**}
*/
