#include "ft_printf.h"

static int	ft_write_str(char **str, t_format_tag *tag, t_data *data)
{
	size_t	len;

	if ((str == NULL)|| (tag == NULL) || (data == NULL))
		return (-1);
	if ((*str == NULL) && !(*str = ft_strdup("(null)")))   // "0x0"
		return (-1);
	len = ft_strlen(*str);
	if (!apply_precision(str, &len, tag) || !apply_alignment(str, &len, tag))
		return (-1);
	data->printf_len += len;
	return (ft_putstr_fd(*str, 1));
}

int		ft_printf_wchar(wint_t c, t_format_tag *tag, t_data *data)
{
	char 	*str;
	wchar_t wstr[2];
	int		result;

	if ((tag == NULL) || (data == NULL))
		return (-1);
	wstr[0] = c;
	wstr[1] = L'\0';
	if(!(str = ft_wchars_to_str(wstr)))
		return (-1);
	result = ft_write_str(&str, tag, data);
	free(str);
	return (result);
}

int		ft_printf_str(t_format_tag *tag, t_data *data)
{
	char	*str;
	wchar_t	*wstr;
	int		result;

	if ((tag == NULL) || (data == NULL))
		return (-1);
	if (tag-> length == TAG_LENGTH_L)
	{
		wstr = va_arg(data->ap, wchar_t *);
		str = ft_wchars_to_str(wstr);
	}
	else
	{
		if ((str = va_arg(data->ap, char *)))
			str = ft_strdup(str);
	}
	result = ft_write_str(&str, tag, data);
	free(str);
	return (result);
}