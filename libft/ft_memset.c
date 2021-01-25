/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:23:01 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/13 06:23:15 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** #include <string.h>
** void		*memset(void *b, int c, size_t len);
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	char_c;
	size_t			i;

	char_c = c;
	i = 0;
	while (i < len)
	{
		((unsigned char*)b)[i] = char_c;
		i++;
	}
	return (b);
}

/*
**int		main(void)
**{
**	printf("====Compare Data Type 'int' & 'unsigned char' For memset====\n");
**	int i;
**	int nums1[5];
**	unsigned char nums2[5];
**
**	memset(nums1, 10, sizeof(nums1));
**	memset(nums2, 10, sizeof(nums2));
**
**	for (i = 0; i < 5; i++)
**		printf("nums1[%d] = %d \n", i, nums1[i]);
**	printf("\n");
**	for (i = 0; i < 5; i++)
**		printf("nums2[%d] = %d \n", i, nums2[i]);
**	printf("\n");
**
**	printf("====Compare Customized ft_memset & Original memset====\n");
**	char chars1[10] = "Born2Code";
**	char chars2[10] = "Born2Code";
**
**	ft_memset(chars1, 'c', sizeof(chars1)-1);
**	memset(chars2, 'c', sizeof(chars2)-1);
**	printf("ft_memset : %s \nmemset : %s\n", chars1, chars2);
**
**	return (0);
**}
*/
