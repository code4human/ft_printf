/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 03:03:05 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/20 02:07:41 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** #include <string.h>
** size_t	strlcpy(char *restrict dst,
**					const char *restrict src, size_t dstsize);
**
** [WARNING]
** The "restrict" qualifier is part of the c99 standard.
** It is therefore forbidden to include it in your prototypes and
** to compile it with the flag -std=c99.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t srcsize;

	if ((dst == NULL) || (src == NULL))
		return (0);
	srcsize = ft_strlen(src);
	if (dstsize < 1)
		return (srcsize);
	i = 0;
	while ((i < srcsize) && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}

/*
**int		main(void)
**{
**	char chararray1[20];
**	char chararray2[20];
**
**	printf("====ft_strlcpy====\n");
**	printf("%lu\n", ft_strlcpy(chararray1, "abcdefghij", sizeof(chararray1)));
**	printf("%s\n", chararray1);
**	printf("====strlcpy====\n");
**	printf("%lu\n", strlcpy(chararray2, "abcdefghij", sizeof(chararray2)));
**	printf("%s\n", chararray2);
**	return (0);
**}
*/
