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

/* ft_printf */
int				ft_printf(const char *format, ...);

/* functions to parse format's tag */
t_format_tag	*ft_printf_get_tag(const char *start, t_data *data);
char			*ft_parse_tag_option(
				char *str, t_format_tag *tag, t_data *data);

/* functions to apply precision, width, flags */
bool			ft_apply_alignment(char **str, size_t *len, t_format_tag *tag);
bool			ft_apply_precision(char **str, size_t *len, t_format_tag *tag);
bool			ft_apply_flag_sharp(
				char **str, size_t *len, t_format_tag *tag, bool is_zero);

/* functions to write format, up to conversions specifier */
int				ft_printf_char(t_format_tag *tag, t_data *data);
int				ft_printf_percent(t_format_tag *tag, t_data *data);
int				ft_printf_str(t_format_tag *tag, t_data *data);
int				ft_printf_wchar(wint_t c, t_format_tag *tag, t_data *data);
char			ft_wchars_to_str(const wchar_t *ws);

int				ft_printf_pointer(t_format_tag *tag, t_data *data);
int				ft_printf_unsigned_number(t_format_tag *tag, t_data *data, char *base);

int				ft_printf_signed_number(t_format_tag *tag, t_data *data);

/* functions for utility */
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strchrset(const char *s, const char *set);
int				ft_printf_putstr_fd(char *s, int fd);
size_t			ft_wchar_utf8_len(wint_t c);
size_t			ft_wstr_utf8_len(const wchar_t *s);

#endif