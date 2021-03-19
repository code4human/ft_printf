/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 06:17:25 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/20 12:35:49 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** char	*ft_strtrim(char const *s1, char const *set);
**
** [WARNING]
** If you need subfunctions to write a complex function,
** you should define these subfunctions as static to avoid publishing them
** with your library.
*/

static	bool	ft_is_occur(char const *set, char const c)
{
	size_t		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (true);
		i++;
	}
	return (false);
}

static	bool	ft_is_blank(int i, int len, char **s3)
{
	if (i >= len)
	{
		*s3 = (char *)malloc(sizeof(char));
		if (!*s3)
			return (false);
		**s3 = '\0';
		return (true);
	}
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		len;
	char		*s2;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	i = 0;
	while (i < len && ft_is_occur(set, s1[i]))
		i++;
	if (ft_is_blank(i, len, &s2) == true)
		return (s2);
	while ((len >= 1) && ft_is_occur(set, s1[len - 1]))
		len--;
	if ((len - 1) - i <= 0)
		return (ft_strdup(""));
	s2 = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!(s2))
		return (NULL);
	ft_strlcpy(s2, (s1 + i), len - i + 1);
	return (s2);
}

/*
**int	main(void)
**{
**	printf("====ft_strtrim====\n");
**	printf("====BCDEF====\n");
**	printf("%s\n", ft_strtrim("ABCDEF", "EAC"));
**	printf("====BCD====\n");
**	printf("%s\n", ft_strtrim("ABCDEF", "AFE"));
**	return (0);
**}
*/
