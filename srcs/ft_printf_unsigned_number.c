/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_number.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:32:33 by taeekim           #+#    #+#             */
/*   Updated: 2021/02/26 15:32:37 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	ft_move_0x(char **str, bool is_upper)
{
	char	*x_addr;

	if ((str == NULL) || (*str == NULL) || !(x_addr = ft_strchrset(*str, "xX")))
		return (false);
	*(x_addr - 1) = (*str)[0];
	(*str)[0] = '0';
	*x_addr = (*str)[1];
	(*str)[1] = is_upper ? 'X' : 'x';
	return (true);
}

static int	ft_write_unsigned_number(char **str, t_format_tag *tag,
									t_data *data, bool is_zero)
{
	size_t	len;

	if ((str == NULL) || (*str == NULL) ||
			(tag == NULL) || (data == NULL))
		return (-1);
	len = ft_strlen(*str);
	if (!ft_apply_precision(str, &len, tag)
		|| !ft_apply_flag_sharp(str, &len, tag, is_zero)
		|| !ft_apply_alignment(str, &len, tag))
		return (-1);
	if (ft_strchr("xX", tag->specifier)
		&& tag->flag_sharp && (tag->precision == -1)
		&& tag->flag_zero && !(is_zero))
		if (!ft_move_0x(str, (tag->specifier == 'X')))
			return (-1);
	data->printf_len += len;
	return (ft_printf_putstr_fd(*str, 1));
}

int			ft_printf_pointer(t_format_tag *tag, t_data *data)
{
	char	*str;
	size_t	addr;
	int		result;

	if ((tag == NULL) || (data == NULL))
		return (-1);
	addr = va_arg(data->ap, size_t);
	tag->flag_sharp = true;
	if ((addr == 0) && (tag->precision == 0))
	{
		if (!(str = ft_strdup("")))
			return (-1);
	}
	else
		str = ft_ulltoa_base((unsigned long long)addr, HEX_STR);
	result = ft_write_unsigned_number(&str, tag, data, false);
	free(str);
	return (result);
}

int			ft_printf_unsigned_number(
				t_format_tag *tag, t_data *data, char *base)
{
	char				*str;
	unsigned long long	arg;
	int					result;

	if ((tag == NULL) || (data == NULL))
		return (-1);
	arg = va_arg(data->ap, unsigned long long);
        if (tag->length == TAG_LENGTH_HH)
                str = ft_ulltoa_base((unsigned char)arg, base);
	else if (tag->length == TAG_LENGTH_H)
		str = ft_ulltoa_base((unsigned short)arg, base);
	else if (tag->length == TAG_LENGTH_L)
		str = ft_ulltoa_base((unsigned long)arg, base);
	else if (tag->length == TAG_LENGTH_LL)
		str = ft_ulltoa_base(arg, base);
	else
		str = ft_ulltoa_base((unsigned int)arg, base);
	if (str == NULL)
		return (-1);
	result = ft_write_unsigned_number(&str, tag, data, (arg == 0));
	free(str);
	return (result);
}
