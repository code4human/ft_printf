/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:51:54 by taeekim           #+#    #+#             */
/*   Updated: 2021/01/26 19:52:57 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TAG_FLAG_SET "-+ #0"
# define TAG_LENGTH_HH 1
# define TAG_LENGTH_H 2
# define TAG_LENGTH_L 3
# define TAG_LENGTH_LL 4
# define TAG_SPECIFIER_SET "cspdiuxXnfge%"

# define DIGIT_STR "0123456789"
# define HEX_STR "0123456789abcdef"
# define HEX_STR_UPPER "0123456789ABCDEF"
# define LLONG_MIN_STR "-9223372036854775808"

# include "libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <wchar.h>
# include <limits.h>

typedef struct	s_data
{
	va_list		ap;
	const char	*format;
	int			printf_len;
}				t_data;

typedef struct	s_format_tag
{
	bool		flag_sign;
	bool		flag_left;
	bool		flag_space;
	bool		flag_sharp;
	bool		flag_zero;
	int			width;
	int			precision;
	char		length;
	char		specifier;
}				t_format_tag;

#endif