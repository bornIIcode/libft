/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:18:27 by ytabia            #+#    #+#             */
/*   Updated: 2024/10/29 10:00:39 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && check_set(set, s1[start]))
		start++;
	while (end > start && check_set(set, s1[end - 1]))
		end--;
	if (start >= end || s1[0] == '\0')
	{
		ptr = ft_strdup("");
		return (ptr);
	}
	ptr = malloc(sizeof(char) * ((end - start) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	ft_strlcpy(ptr, s1 + start, end - start + 1);
	return (ptr);
}