#include "ft_printf.h"

/*
** [PROTOTYPE]
** #include <string.h>
** char		*ft_strndup(const char *s1, size_t n);
*/

char		*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	size_t	len;
	char	*s2;

	if (n <= 0 || !(len = ft_strlen(s1)))
		return (ft_strdup(""));
	len = n < len ? n : len;
	if (!(s2 = malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char		*ft_strchrset(const char *s, const char *set)
{
	size_t	i;
	size_t	j;

	if ((s == NULL) || (set == NULL))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (set[i] != '\0')
		{
			if (s[i] == set[j])
				return ((char *)s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}