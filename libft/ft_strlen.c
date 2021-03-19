/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 00:29:34 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/01 07:44:59 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** #include <string.h>
** size_t	strlen(const char *s);
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

/*
**int	main(void)
**{
**	printf("====ft_strlen====\n");
**	printf("%ld\n", ft_strlen("42Seoul"));
**	printf("====strlen====\n");
**	printf("%ld\n", strlen("42Seoul"));
**	return (0);
**}
*/
