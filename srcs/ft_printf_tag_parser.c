#include "ft_printf.h"

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
	// tag_str을 바탕으로 tag 구조체 변수 값 세팅 (함수 분리)
	free(tag_str);
	return (tag);
}