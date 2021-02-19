/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:24:46 by taeekim           #+#    #+#             */
/*   Updated: 2021/01/26 19:57:00 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_write_format(t_format_tag *tag, t_data *data)
{
	if ((tag == NULL) || (data == NULL))
		return (-1);
	if (tag->specifier == 'c')
		return (ft_printf_char(tag, data));
	else if (tag->specifier == '%')
		return (ft_printf_percent(tag, data));
	else if (tag->specifier == 's')
		return (ft_printf_str(tag, data));
	else if (tag->specifier == 'p')
		return (ft_printf_pointer(tag, data));
	else if (tag->specifier == 'n')
		return (ft_printf_pointer(tag, data));
	else if (tag->specifier == 'u')
		return (ft_printf_unsigned_number(tag, data, DIGIT_STR));
	else if (tag->specifier == 'x')
		return (ft_printf_unsigned_number(tag, data, HEX_STR));
	else if (tag->specifier == 'X')
		return (ft_printf_unsigned_number(tag, data, HEX_STR_UPPER));
	else if ((tag->specifier == 'd') || (tag->specifier == 'i'))
		return (ft_printf_signed_number(tag, data));
	else if (tag->specifier == 'e' || tag->specifier == 'E')
		return (ft_printf_signed_number(tag, data));
	return (-1);
}

static bool			ft_write_text(t_data *data, size_t write_len)
{
	int				len;

	if ((data == NULL) || (write_len < 0))
		return (false);
	len = write(1, data->format, write_len);
	if (len < 0)
		return (false);
	data->printf_len += len;
	data->format += len;
	return (true);
}

static int			ft_write(t_data *data)
{
	t_format_tag	*tag;
	char			*tag_start;
	int				result;

	while (!(tag_start = ft_strchr(data->format, '%')))
	{
		if (!(ft_write_text(data, tag_start - data->format))
			|| !(tag = ft_printf_get_tag(tag_start, data)))
			return (-1);
		result = ft_write_format(tag, data);
		free(tag);
		if (result == -1)
			return (-1);
	}
	if (!ft_write_text(data, ft_strlen(data->format)))
		return (-1);
	return (data->printf_len);
}

int					ft_printf(const char *format, ...)
{
	t_data			data;

	if (format == NULL)
		return (-1);
	va_start(data.ap, format);
	data.format = format;
	data.printf_len = 0;
	if (ft_write(&data) == -1)
		data.printf_len = -1;
	va_end(data.ap);
	return (data.printf_len);
}