#include "ft_printf.h"

static char	*ft_parse_flags(char *tag_str, t_format_tag *tag)
{
	char	*flag_addr;
	char	flag;

	if ((tag_str == NULL) || (tag == NULL))
		return (NULL);
	while ((flag_addr = ft_strchr(TAG_FLAG_SET, *tag_str)))
	{
		flag = TAG_FLAG_SET[flag_addr - TAG_FLAG_SET];
		if (flag == '-')
			tag->flag_left = true;
		else if (flag == '+')
			tag->flag_sign = true;
		else if (flag == ' ')
			tag->flag_space = true;
		else if (flag == '#')
			tag->flag_sharp = true;
		else if (flag == '0')
			tag->flag_zero = true;
		else
			return (NULL);
		tag_str++;
	}
	return (tag_str);
}

static char	*ft_parse_width(char *tag_str, t_format_tag *tag, t_data *data)
{
	char	*c_addr;
	int		n;

	if ((tag_str == NULL) || (tag == NULL) || (data == NULL))
		return (NULL);
	if (*tag_str == '*')
	{
		n = va_arg(data->ap, int);
		if (n < 0)
		{
			tag->flag_left = true;
			n *= -1;
		}
		tag->width = n;
		return (++tag_str);
	}
	if (!ft_isdigit(*tag_str) || *tag_str == '0')
		return (tag_str);
	while ((c_addr = ft_strchr(DIGIT_STR, *tag_str)))
	{
		n = DIGIT_STR[c_addr - DIGIT_STR] - '0'; 
		tag->width = tag->width * 10 + n;
		tag_str++;
	}
	return (tag_str);
}

static char *ft_parse_precision(char *tag_str, t_format_tag *tag, t_data *data)
{
	char	*c_addr;
	int		n;

	if ((tag_str == NULL) || (tag == NULL) || (data == NULL))
		return (NULL);
	if (*tag_str != '.')
		return (tag_str);
	tag_str++;
	if (*tag_str == '*')
	{
		n = va_arg(data->ap, int);
		if (n < 0)
			n = -1;
		tag->precision = n;
		return(++tag_str);
	}
	tag->precision = 0;
	while ((c_addr = ft_strchr(DIGIT_STR, *tag_str)))
	{
		n = DIGIT_STR[c_addr - DIGIT_STR] - '0';
		tag->precision = tag->precision * 10 + n;
		tag_str++;
	}
	return (tag_str);
}

static char *ft_parse_length(char *tag_str, t_format_tag *tag)
{
	if ((tag_str == NULL) || (tag == NULL))
		return (NULL);
	if (*tag_str == 'l')
	{
		tag->length = TAG_LENGTH_L;
		tag_str++;
		if (*tag_str == 'l')
		{
			tag->length = TAG_LENGTH_LL;
			tag_str++;
		}
	}
	else if (*tag_str == 'h')
	{
		tag->length = TAG_LENGTH_H;
		tag_str++;
		if (*tag_str == 'h')
		{
			tag->length = TAG_LENGTH_HH;
			tag_str++;
		}
	}
	return (tag_str);
}

char		*ft_parse_tag_option(
	char *str, t_format_tag *tag, t_data *data)
{
	if ((str == NULL) || (tag == NULL) || (data == NULL)
		|| !(str = ft_parse_flags(str, tag))
		|| !(str = ft_parse_width(str, tag, data))
		|| !(str - ft_parse_precision(str, tag, data))
		|| !(str = ft_parse_length(str, tag)))
		return (NULL);
	return (str);
}
