#include "ft_printf.h"

static int	ft_write_unsigned_num(char **str, t_format_tag *tag, 
									t_data *data, bool is_zero)
{
	size_t	len;

	if ((str == NULL) || (*str == NULL) || 
			(tag == NULL) || (data == NULL))
		return (-1);
	len = ft_strlen(*str);
	if (!ft_apply_precision(str, &len, tag)
		|| !
		|| )
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
		{
			return (-1);
		}
	}
	else
		str = 
	result = 
	free(str);
	return (result);
}