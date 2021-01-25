/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:22:47 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/13 06:27:08 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** #include <string.h>
** void *memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
**
** [WARNING]
** The "restrict" qualifier is part of the c99 standard.
** It is therefore forbidden to include it in your prototypes and
** to compile it with the flag -std=c99.
*/

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*char_dst;
	unsigned char	*char_src;

	char_dst = (unsigned char *)dst;
	char_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		char_dst[i] = char_src[i];
		if (char_src[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

/*
**int	main(void)
**{
**	char chararray1[20];
**	char chararray2[20];
**
**	printf("====ft_memccpy====\n");
**	printf("%s\n%p\n", chararray1, ft_memccpy(chararray1, "42Seoul", 50, 6));
**	printf("====memcpy====\n");
**	printf("%s\n%p\n", chararray2, memccpy(chararray2, "42Seoul", 50, 6));
**	return (0);
**}
*/
