/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:23:02 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/13 06:27:23 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** #include <string.h>
** void	*memchr(const void *s, int c, size_t n);
*/

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*char_s;

	char_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (char_s[i] == (unsigned char)c)
			return (void *)(s + i);
		i++;
	}
	return (NULL);
}

/*
**int   main(void)
**{
**	printf("====ft_memchr====\n");
**	printf("%p\n", ft_memchr("42Cadet", 67, 6));
**	printf("====memchr====\n");
**	printf("%p\n", memchr("42Cadet", 67, 6));
**	return (0);
**}
*/
