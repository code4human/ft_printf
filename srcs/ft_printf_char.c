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

int	ft_printf_char(t_format_tag *tag, t_data *data)
{
	if ((tag == NULL) || (data == NULL))
		return (-1);

}

int	ft_printf_percent(t_format_tag *tag, t_data *data)
{
	int		result;

	if ((tag == NULL) || (data == NULL))
		return (-1);
	
}