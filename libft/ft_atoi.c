/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:04:27 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/17 18:11:53 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** #include <stdlib.h>
** int	atoi(const char *nptr);
**
** [WARNING]
** If you need subfunctions to write a complex function,
** you should define these subfunctions as static to avoid publishing them
** with your library.
*/

static	int		ft_is_white_space(const char *c)
{
	if (*c == ' ' || *c == '\n' || *c == '\r'
			|| *c == '\t' || *c == '\f' || *c == '\v')
		return (1);
	else
		return (0);
}

static	int		ft_is_plus_minus(const char *c)
{
	if (*c == '+' || *c == '-')
		return (1);
	else
		return (0);
}

static	int		ft_is_number(const char *c)
{
	if (*c >= '0' && *c <= '9')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *nptr)
{
	int sign;
	int res;

	sign = 1;
	res = 0;
	while (ft_is_white_space(nptr))
		nptr++;
	if (ft_is_plus_minus(nptr))
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_is_number(nptr))
	{
		res *= 10;
		res += (*nptr - '0');
		nptr++;
	}
	return (sign * res);
}

/*
**int		main(void)
**{
**	printf("====ft_atoi====\n");
**	printf("%d\n%d\n%d\n%d\n%d\n%d\n",
**		ft_atoi("-283"), ft_atoi("  -+--283"), ft_atoi("283!20"),
**	      ft_atoi("283a30"), ft_atoi("a30"), ft_atoi("!@#"));
**	printf("====atoi====\n");
**	printf("%d\n%d\n%d\n%d\n%d\n%d\n",
**		atoi("-283"), atoi("  -+--283"), atoi("283!20"),
**	      atoi("283a30"), atoi("a30"), atoi("!@#"));
**}
*/
