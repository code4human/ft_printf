#include "ft_printf.h"

static int  ft_utf8_2byte_fd(wint_t c, int fd)
{
    unsigned char buf[2];

    buf[0] = (c >> 6) | 0b11000000;
    buf[1] = (c & 0b111111) | 0b10000000;
	return (write(fd, buf, 2));
}

static int  ft_utf8_3byte_fd(wint_t c, int fd)
{
	unsigned char buf[3];

	buf[0] = (c >> 12) | 0b11100000;
	buf[1] = ((c >> 6) & 0b111111) | 0b10000000;
	buf[2] = (c & 0b111111) | 0b10000000;
	return (write(fd, buf, 3));
}

static int  ft_utf8_4byte_fd(wint_t c, int fd)
{
	unsigned char buf[4];

	buf[0] = (c >> 18) | 0b11110000;
	buf[1] = ((c >> 12) & 0b111111) | 0b10000000;
	buf[2] = ((c >> 6) & 0b111111) | 0b10000000;
	buf[3] = (c & 0b111111) | 0b10000000;
	return (write(fd, buf, 4));
}

int         ft_putwchar_fd(wint_t c, int fd)
{
    if (fd < 0)
        return (-1);
    if (c < 128)
        return (write(fd, &c, 1));
    if (c < 2048)
        return (ft_utf8_2byte_fd(wint_t c, int fd));
    if (c < 65536)
        return (ft_utf8_3byte_fd(wint_t c, int fd));
    if (c < 2097152)
        return (ft_utf8_4byte_fd(wint_t c, int fd));
    return (-1);
}

static int  ft_utf8_2byte_to_str(char *dst, wint_t c)
{
    dst[0] = (c >> 6) | 0b11000000;
	dst[1] = (c & 0b111111) | 0b10000000;
	return (2);
}

static int	ft_utf8_3byte_to_str(char *dst, wint_t c)
{
	dst[0] = (c >> 12) | 0b11100000;
	dst[1] = ((c >> 6) & 0b111111) | 0b10000000;
	dst[2] = (c & 0b111111) | 0b10000000;
	return (3);
}

static int	ft_utf8_4byte_to_str(char *dst, wint_t c)
{
	dst[0] = (c >> 18) | 0b11110000;
	dst[1] = ((c >> 12) & 0b111111) | 0b10000000;
	dst[2] = ((c >> 6) & 0b111111) | 0b10000000;
	dst[3] = (c & 0b111111) | 0b10000000;
	return (4);
}

static int	ft_utf8_str(char *dst, wint_t c)
{
	if (c < 128)
	{
		dst[0] = c;
		return (1);
	}
	if (c < 2048)
		return (ft_utf8_2byte_to_str(dst, c));
	if (c < 65536)
		return (ft_utf8_3byte_to_str(dst, c));
	if (c < 2097152)
		return (ft_utf8_4byte_to_str(dst, c));
	return (-1);
}

char        ft_wchars_to_str(const wchar_t *ws)
{
    char    *str;
    size_t  len;
    size_t  i;
    size_t  j;
    int     temp;

    if (ws == NULL)
        return (NULL);
    len = ft_wstr_utf8_len(ws);
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
    i = 0;
	j = 0;
	while (ws[i] != L'\0')
	{
		if ((temp = ft_utf8_str(str + j, ws[i])) == -1)
		{
			free(str);
			return (NULL);
		}
		j += temp;
		i++;
	}
	str[len] = '\0';
	return (str);
}