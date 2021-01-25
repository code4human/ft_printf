/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:22:26 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/19 23:54:37 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** #include <string.h>
** void	*memcpy(void *restrict dst, const void *restrict src, size_t n);
**
** [WARNING]
** The "restrict" qualifier is part of the c99 standard.
** It is therefore forbidden to include it in your prototypes and
** to compile it with the flag -std=c99.
*/

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*char_dst;
	unsigned char	*char_src;

	char_dst = (unsigned char *)dst;
	char_src = (unsigned char *)src;
	if ((char_dst == NULL) && (char_src == NULL))
		return (NULL);
	i = 0;
	while (i < n)
	{
		char_dst[i] = char_src[i];
		i++;
	}
	return (dst);
}

/*
**int	main(void)
**{
**	char	chararray1[20];
**	char	chararray2[20];
**
**	printf("====ft_memcpy====\n");
**	printf("%s\n%p\n", chararray1,
**				ft_memcpy(chararray1, "1234567", sizeof(chararray1)));
**	printf("====memcpy====\n");
**	printf("%s\n%p\n", chararray2,
**				memcpy(chararray2, "1234567", sizeof(chararray2)));
**	return (0);
**}
*/
