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

static bool		ft_printf_print_text(t_data *data, size_t write_len)
{
	int len;

	if (!data || write_len < 0)
		return (false);
	len = write(1, data.format, write_len);
	if (len < 0)
		return (false);
	data.len += len;
	return (true);
}

static int		ft_printf_print(t_data *data)
{
	t_format_tag	*tag;
	char			*tag_start;
	int				result;

	while (!(tag_start = ft_strchr(data.format, '%')))
	{
		if (!ft_printf_print_text(data, tag_start - data.format))
			return (-1);
	}
	if (!ft_printf_print_text(data, ft_strlen(data.format)))
		return (-1);
	return (data.len);
}

int		ft_printf(const char *format, ...)
{
	t_data	data;

	if (format == NULL)
		return (-1);
	va_start(data.ap, format);
	data.format = format;
	data.len = 0;
	if (ft_printf_print(&data) == -1)
		data.len = -1;
	va_end(data.ap);
	return (data.len);	
}
