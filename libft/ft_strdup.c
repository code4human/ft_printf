/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 12:44:45 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/13 07:00:04 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** #include <string.h>
** char		*strdup(const char *s1);
*/

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!(s2))
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*
**int	main(void)
**{
**	printf("====ft_strdup====\n");
**	printf("%s\n", ft_strdup("42Seoul"));
**	printf("====strdup====\n");
**	printf("%s\n", strdup("42Seoul"));
**}
*/
