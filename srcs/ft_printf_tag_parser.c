#include "ft_printf.h"

static t_format_tag *ft_init_tag(void)
{
    t_format_tag    *tag;

    if (!(tag = (t_format_tag *)malloc(sizeof(t_format_tag))))
        return (NULL);
    tag->flag_sign = false;
    tag->flag_left = false;
    tag->flag_space = false;
    tag->flag_sharp = false;
    tag->flag_zero = false;
    tag->width = 0;
    tag->precision = -1;
    tag->length = 0;
    tag->specifier = '\0';
    return (tag);
}

static char 	*ft_parse_specifier(char *tag_str, t_format_tag *tag)
{
	char		*specifier_addr;
	char 		c;

	if ((tag_str == NULL) || (tag == NULL)
		|| !(specifier_addr = ft_strchr(TAG_SPECIFIER_SET, *tag_str)))
		return (NULL);
	c = TAG_SPECIFIER_SET[specifier_addr - TAG_SPECIFIER_SET];
	tag->specifier = c;
	tag_str++;
	return (tag_str);	
}

static t_format_tag	*ft_parse_tag(char *tag_str, t_data *data)
{
	t_format_tag	*tag;

	if ((tag_str == NULL) || (data == NULL) || !(tag = ft_init_tag()))
		return (NULL);
	if (!(tag_str = ft_parse_tag_option(tag_str, tag, data))
		|| !(tag_str = ft_parse_specifier(tag_str, tag)))
	{
		free(tag);
		tag = NULL;
	}
	return (tag);
}

t_format_tag		*ft_printf_get_tag(const char *start, t_data *data)
{
	char			*end;
	char			*tag_str;
	size_t			len;
	t_format_tag	*tag;

	start++;
	if ((start == NULL) || (data == NULL)
		|| !(end = ft_strchrset(start, TAG_SPECIFIER_SET)))
		return (NULL);
	len = end - start + 1;
	data->format += len + 1;
	if (!(tag_str = ft_strndup(start, len)))
		return (NULL);
	tag = ft_parse_tag(tag_str, data);
	free(tag_str);
	return (tag);
}