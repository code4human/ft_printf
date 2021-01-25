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
	i = 0;
	while (((s1[i] != '\0') || (s2[i] != '\0')) && (i < n))
	{
		if (s1[i] != s2[i])
			return (u1[i] - u2[i]);
		i++;
	}
	return (0);
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
