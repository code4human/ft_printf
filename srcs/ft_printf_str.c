#include "ft_printf.h"

static int	ft_write_str(char **str, t_format_tag *tag, t_data *data)
{
	/* code */
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
	int		result;

	if ((tag == NULL) || (data == NULL))
		return (-1);
	/* 구현 */
	/* ft_write_str 으로 넘겨주기 */
}