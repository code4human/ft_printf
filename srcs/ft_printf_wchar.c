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