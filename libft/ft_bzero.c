/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 05:34:26 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/13 06:40:42 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** #include <strings.h>
** void		bzero(void *s, size_t n);
*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*char_s;
	size_t			i;

	char_s = s;
	i = 0;
	while (i < n)
	{
		char_s[i] = 0;
		i++;
	}
}

/*
**int		main(void)
**{
**	char chars1[10] = "Born2Code";
**	char chars2[10] = "Born2Code";
**
**	printf("====ft_bzero====\n");
**	ft_bzero(chars1, sizeof(chars1)-1);
**	printf("%s\n", chars1);
**	printf("====bzero====\n");
**	bzero(chars2, sizeof(chars2)-1);
**	printf("%s\n", chars2);
**}
*/
