/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 08:22:12 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/13 06:17:37 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** #include <string.h>
** size_t  strlcat(char *dst, const char *src, size_t dstsize);
**
** [WARNING]
** The "restrict" qualifier is part of the c99 standard.
** It is therefore forbidden to include it in your prototypes and
** to compile it with the flag -std=c99.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	init_dstsize;
	size_t	srcsize;

	init_dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	if (dstsize == 0)
		return (srcsize);
	else if (dstsize <= init_dstsize)
		return (dstsize + srcsize);
	i = 0;
	while ((i < srcsize) && (init_dstsize + i < dstsize - 1))
	{
		dst[init_dstsize + i] = src[i];
		i++;
	}
	dst[init_dstsize + i] = '\0';
	return (init_dstsize + srcsize);
}

/*
**int		main(void)
**{
**	char chararray1[30] = "From_LaPiscine_To_";
**	char chararray2[30] = "From_LaPiscine_To_";
**
**	printf("====ft_strlcat====\n");
**	printf("%zd\n", ft_strlcat(chararray1, "42cursus", 18));
**	printf("%s\n", chararray1);
**	printf("====strlcat====\n");
**	printf("%zd\n", strlcat(chararray2, "42cursus", 18));
**	printf("%s\n", chararray2);
**	return (0);
**}
*/
