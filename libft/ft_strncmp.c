/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:24:33 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/13 06:22:51 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** #include <string.h>
** int	strncmp(const char *s1, const char *s2, size_t n);
*/

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	if ((u1 == NULL) && (u2 == NULL))
		return (0);
	else if ((u1 == NULL) || (u2 == NULL))
		return (u1 == NULL ? -1 : 1);
	i = 0;
	while (((u1[i] != '\0') || (u2[i] != '\0')) && (i < n))
	{
		if (u1[i] != u2[i])
			return (u1[i] - u2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (u1[i] - u2[i]);
}

/*
**int	main(void)
**{
**	printf("====ft_strncmp====\n");
**	printf("%d\n%d\n", ft_strncmp("42Seoul_Libft", "42Seoul_libft", 10),
**				ft_strncmp("42Seoul_Libft", "42Seoul", 10));
**	printf("====strncmp====\n");
**	printf("%d\n%d\n", strncmp("42Seoul_Libft", "42Seoul_libft", 10),
**				strncmp("42Seoul_Libft", "42Seoul", 10));
**	return (0);
**}
*/
