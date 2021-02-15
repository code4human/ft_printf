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

int			ft_printf_putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return (-1);
	return (write(fd, s, ft_strlen(s)));
}

size_t		ft_wchar_utf8_len(wint_t c)
{
	if (c < 128)
		return (1);
	if (c < 2048)
		return (2);
	if (c < 65536)
		return (3);
	if (c < 2097152)
		return (4);
	return (0);
}

size_t		ft_wstr_utf8_len(const wchar_t *s)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i] != L'\0')
	{
		len += ft_wchar_utf8_len(s[i]);
		i++;
	}
	return (len);
}