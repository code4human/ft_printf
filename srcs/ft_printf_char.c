/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:24:46 by taeekim           #+#    #+#             */
/*   Updated: 2021/01/26 19:57:00 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_apply_alignment_char(t_format_tag *tag, size_t *len)
{
	char	*temp;
	char	c;

	if (tag == NULL)
		return (NULL);
}

static int	ft_write_char(char c, t_format_tag *tag, t_data *data)
{
	size_t	len;
	char	*str;
	int		result1;
	int		result2;

	if ((tag == NULL) || (data == NULL))
		return (-1);
	len = 1;
	if (!(str = ft_apply_alignment_char(tag, &len)))
		return (-1);
	data->len += len;
	if (tag->flag_left)
	{
		result1 = write(1, c, 1);
		result2 = write(1, str, ft_strlen(str));
	}
	else
	{
		result2 = write(1, str, ft_strlen(str));
		result1 = write(1, c, 1);
	}
	free(str);
	if ((result1 != 1) || (result2 < 0))
		return (-1);
	return (len);
}

int		ft_printf_percent(t_format_tag *tag, t_data *data)
{
	if ((tag == NULL) || (data == NULL))
		return (-1);
	return (ft_write_char('%', tag, data));
}

int			ft_printf_char(t_format_tag *tag, t_data *data)
{
	int		c;
	wint_t	wc;
	int		result;

	if ((tag == NULL) || (data == NULL))
		return (-1);
	if (tag->length == TAG_LENGTH_L)
	{
		if ((wc = va_arg(data->ap, wint_t)) != L'\0')
			return (ft_printf_wchar(wc, tag, data));
		c = wc;
	}
	else
		c = va_arg(data->ap, int);
	result = ft_write_char(c, tag, data);
	return (result);
}