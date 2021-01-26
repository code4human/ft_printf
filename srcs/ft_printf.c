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

int			ft_printf_print(t_data *data)
{

}

int			ft_printf(const char *format, ...)
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
