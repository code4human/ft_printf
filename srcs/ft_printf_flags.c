#include "ft_printf.h"

bool		apply_alignment(char **str, size_t *len, t_format_tag *tag)
{
	char	*temp;

	if ((str == NULL)|| (*str == NULL) || (tag == NULL) || (len == NULL))
		return (false);
	if (*len >= (size_t)tag->width)
		return (true);
	if (!(temp = malloc(tag->width + 1)))
		return (false);
	if (tag->flag_left)
	{
		ft_strlcpy(temp, *str, *len + 1);
		ft_memset(temp + *len, ' ', tag->width - *len);
		temp[tag->width] = '\0';
	}
	else
	{
		ft_memset(temp, tag->flag_zero && (tag->precision < 0 ||
				ft_strchr("eE", tag->specifier)) ? '0' : ' ',
				tag->width - *len);
		ft_strlcpy(temp + tag->width - *len, *str, *len + 1);
	}
	free(*str);
	*str = temp;
	*len = tag->width;
	return (true);
}

static bool	ft_apply_precision2(char **str, size_t *len, t_format_tag *tag)
{
	char	*temp;

	if (ft_strchr("diuxX", tag->specifier))
	{
		if (*len < (size_t)tag->precision)
		{
			if (!(temp = (char *)malloc(tag->precision + 1)))
				return (false);
			ft_memset(temp, '0', tag->precision - *len);
			ft_strlcpy(temp + tag->precision - *len, *str, *len + 1);
			free(*str);
			*str = temp;
			*len = tag->precision;
		}
		else if ((tag->precision == 0) && (*str[0] == '0'))
		{
			if (!(temp = ft_strdup("")))
				return (false);
			free(*str);
			*str = temp;
			*len = tag->precision;
		}
		return (true);
	}
	return (true);
}

bool		ft_apply_precision(char **str, size_t *len, t_format_tag *tag)
{
	char	*temp;

	if ((str == NULL)|| (*str == NULL) || (tag == NULL))
		return (false);
	if (tag->precision < 0)
		return (true);
	if (tag->specifier == 's')
	{
		if (*len > (size_t)tag->precision)
		{
			if (!(temp = ft_strndup(*str, tag->precision)))
				return (false);
			free(*str);
			*str = temp;
			*len = tag->precision;
		}
		return (true);
	}
	return (apply_precision2(str, len, tag));
}