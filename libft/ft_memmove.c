/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 06:16:40 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/20 01:38:12 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** #include <string.h>
** void *memmove(void *dst, const void *src, size_t len);
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*char_dst;
	unsigned char	*char_src;

	char_dst = (unsigned char *)dst;
	char_src = (unsigned char *)src;
	if ((char_dst == NULL) && (char_src == NULL))
		return (NULL);
	if ((src < dst) && (dst < src + len))
	{
		while (len > 0)
		{
			char_dst[len - 1] = char_src[len - 1];
			len--;
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}

/*
**int	main(void)
**{
**	char	chars1[] = "42Seoul is very good......";
**	char	chars2[] = "42Seoul is very good......";
**
**	printf("====42Seoul is very very good.====\n");
**	printf("====ft_memmove====\n");
**	ft_memmove(chars1 + 16, chars1 + 11, 9);
**	printf("%s\n", chars1);
**	printf("====memmove====\n");
**	memmove(chars2 + 16, chars2 + 11, 9);
**	printf("%s\n", chars2);
**	return (0);
**}
*/
