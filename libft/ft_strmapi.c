/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 06:18:50 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/13 06:11:51 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
*/

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	s_len;
	char			*result;

	if ((s == NULL) || (f == NULL))
		return (NULL);
	s_len = ft_strlen(s);
	if (!(result = (char *)malloc(sizeof(char) * (s_len + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
**static char	ft_odd_index_upper(unsigned int n, char c)
**{
**	if (n % 2 != 0)
**		if (c >= 'a' && c <= 'z')
**			return (c - 32);
**		else
**			return (c);
**	else
**		return (c);
**}
**
**int	main(void)
**{
**	printf("====ft_strmapi====\n");
**	printf("====cAdEt42SeOuL====\n");
**	printf("%s\n", ft_strmapi("cadet42seoul", ft_odd_index_upper));
**	return (0);
**}
*/
