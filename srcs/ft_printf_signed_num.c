#include "ft_printf.h"

static bool	ft_add_sign(char **str, size_t *len,
	t_format_tag *tag, bool is_negative)
{
	char	*temp;

	if ((str == NULL) || (*str == NULL) || (tag == NULL))
		return (false);
	if (!(tag->flag_sign) && !(tag->flag_space) && !(is_negative))
		return (true);
	if (!(temp = (char *)malloc(*len + 2)))
		return (false);
	*len++;
	temp[0] = tag->flag_sign ? '+' : '-';
	temp[0] = is_negative ? '-' : temp[0];
	ft_strlcpy(temp + 1, *str, *len);
	free(*str);
	*str = temp;
	return (true);
}

static int	ft_move_sign(char *str, t_format_tag *tag, bool is_negative)
{
	char	*sign_addr;
	char	c;

	if ((str == NULL) || (*str == NULL))
		return (-1);
	if (!(tag->flag_zero) || 
		!(tag->flag_sign) && !(tag->flag_space) && !(is_negative))
		return (true);
	if (!(sign_addr = ft_strchrset(str, tag->flag_sign ? "+- " : "+-")))
		return (false);
	c = *sign_addr;
	*sign_addr = str[0];
	str[0] = c;
	return (true);
}

static int	ft_write_signed_num(char **str, t_format_tag *tag, t_data *data)
{
	size_t	len;
	bool	is_negative;
	char	*temp;

	if ((str == NULL) || (*str == NULL) || 
			(tag == NULL) || (data == NULL))
		return (-1);
	is_negative = false;
	if ((*str[0]) == '-')
	{
		is_negative = true;
		if (!(temp = ft_strdup(*str + 1)))
			return (-1);
		free(*str);
		*str = temp;
	}
	len = ft_strlen(*str);
	if (!ft_apply_precision(str, &len, tag)
		|| !ft_add_sign(str, &len, tag, is_negative)
		|| !ft_apply_alignment(str, &len, tag)
		|| (tag->precision < 0) && !(ft_move_sign(*str, tag, is_negative)))
		return (-1);
	data->printf_len += len;
	return (ft_printf_putstr_fd(*str, 1));
}

int			ft_printf_signed_number(t_format_tag *tag, t_data *data)
{
	char		*str;
	long long	arg;
	int			result;

	if ((tag == NULL) || (data == NULL))
		return (-1);
	if (tag->length == TAG_LENGTH_HH)
		arg = (char)va_arg(data->ap, int);
	else if (tag->length == TAG_LENGTH_H)
		arg = (short)va_arg(data->ap, int);
	else if (tag->length == TAG_LENGTH_L)
		arg = (long)va_arg(data->ap, long);
	else if (tag->length == TAG_LENGTH_LL)
		arg = (long long)va_arg(data->ap, long long);
	else
		arg = (int)va_arg(data->ap, int);
	if (!(str = ft_lltoa_base((long long)arg, NULL)))
		return (-1);
	result = ft_write_signed_num(&str, tag, data);
	free(str);
	return (result);
}