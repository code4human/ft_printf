/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 06:17:41 by taeekim           #+#    #+#             */
/*   Updated: 2020/10/20 12:38:51 by taeekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [PROTOTYPE]
** char **ft_split(char const *s, char c);
**
** [WARNING]
** If you need subfunctions to write a complex function,
** you should define these subfunctions as static to avoid publishing them
** with your library.
*/

static char		**ft_malloc_error(char **result)
{
	size_t		idx2;

	idx2 = 0;
	while (result[idx2])
	{
		free(result[idx2]);
		result[idx2] = NULL;
		idx2++;
	}
	free(result);
	return (NULL);
}

static size_t	ft_word_break(char const *s, char c)
{
	size_t		idx1;
	size_t		n_break;

	idx1 = 0;
	n_break = 0;
	while (s[idx1])
	{
		if (s[idx1] == c)
			idx1++;
		else
		{
			n_break++;
			while (s[idx1] && s[idx1] != c)
				idx1++;
		}
	}
	return (n_break);
}

static char		*ft_word_cpy(char *word, size_t word_len,
					char const *s, int pre_idx1)
{
	size_t		idx3;

	idx3 = 0;
	while (idx3 < word_len)
	{
		word[idx3] = s[pre_idx1 + idx3];
		idx3++;
	}
	word[idx3] = '\0';
	return (word);
}

static char		**ft_word_malloc(char **result,
				size_t n_break, char const *s, char c)
{
	size_t		idx2;
	size_t		idx1;
	size_t		pre_idx1;
	size_t		word_len;

	idx2 = 0;
	idx1 = 0;
	word_len = 0;
	while (s[idx1] && idx2 < n_break)
	{
		while (s[idx1] && s[idx1] == c)
			idx1++;
		pre_idx1 = idx1;
		while (s[idx1] && s[idx1++] != c)
			word_len++;
		if (!(result[idx2] = (char *)malloc(sizeof(char) * (word_len + 1))))
			return (ft_malloc_error(result));
		ft_word_cpy(result[idx2], word_len, s, pre_idx1);
		word_len = 0;
		idx2++;
	}
	result[idx2] = 0;
	return (result);
}

char			**ft_split(char const *s, char c)
{
	size_t		n_break;
	char		**result;

	if (s == NULL)
		return (NULL);
	n_break = ft_word_break(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (n_break + 1))))
		return (NULL);
	result[n_break] = NULL;
	ft_word_malloc(result, n_break, s, c);
	return (result);
}

/*
**int main(void)
**{
**	printf("====ft_split====\n");
**	char **a = ft_split("42_Seoul_Cadet", '_');
**	for(int i = 0; i < 3; i++)
**		printf("%s\n", a[i]);
**	return (0);
**}
*/
