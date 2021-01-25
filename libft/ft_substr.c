/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 06:16:56 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/20 12:54:26 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** char	*ft_substr(char const *s, unsigned int start, size_t len);
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substring;

	if (s == NULL)
		return (NULL);
	if (!(substring = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	while ((i < len) && (i + start < s_len))
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

/*
**int	main(void)
**{
**	printf("====ft_substr====\n");
**	printf("%s\n", ft_substr("BornToSeoul", 2, 6));
**	return (0);
**}
*/
