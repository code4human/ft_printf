/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:27:41 by taeekim           #+#    #+#             */
/*   Updated: 2021/02/26 15:30:44 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_count(t_format_tag *tag, t_data *data)
{
	int *len;

	if ((tag == NULL) || (data == NULL))
		return (-1);
	if (!(len = va_arg(data->ap, int *)))
		return (-1);
	*len = data->printf_len;
	return (*len);
}