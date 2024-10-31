/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:16:03 by ytabia            #+#    #+#             */
/*   Updated: 2024/10/29 12:16:58 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	**memerror(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}






char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**result;
	size_t	num_words;
	size_t	start;
	size_t	word_len;

	i = 0;
	j = 0;
	num_words = count_words(s, c);
	result = malloc(sizeof(char *) * (num_words + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		word_len = 0;
		while (s[i + word_len] && s[i + word_len] != c)
			word_len++;
		if (word_len > 0)
		{
			result[j] = ft_substr(s, start, word_len);
			if (!result[j])
				return (memerror(result));
			j++;
			i += word_len;
		}
	}
	result[j] = NULL;
	return (result);
}

int	main(void)
{
	char str[] = "hello to my world";
	char c = ' ';
	char **ptr = ft_split(str, c);
	int i = 0;
	while (ptr && ptr[i])
	{
		printf("%s\n", ptr[i]);
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
}