/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 06:15:52 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/13 06:40:17 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** #include <string.h>
** int memcmp(const void *s1, const void *s2, size_t n);
**
** [WARNING]
** The memcmp() returns actually 1, 0, -1.
*/

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*char_s1;
	unsigned char	*char_s2;

	if (n == 0)
		return (0);
	char_s1 = (unsigned char *)s1;
	char_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (char_s1[i] != char_s2[i])
			return (char_s1[i] - char_s2[i]);
		i++;
	}
	return (0);
}

/*
**int	main(void)
**{
**	printf("====ft_memcmp====\n");
**	printf("%d\n", ft_memcmp("42", "Seoul", 2));
**	printf("====memcmp====\n");
**	printf("%d\n", memcmp("42", "Seoul", 2));
**	return (0);
**}
*/
