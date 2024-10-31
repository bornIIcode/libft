/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:08:59 by ytabia            #+#    #+#             */
/*   Updated: 2024/10/30 15:37:15 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char f(unsigned int i, char c)
{
	if(c >= 'a' && c <= 'z')
		return(c - 32);
	return(c);
}


char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{

	unsigned int i;
	char *ptr;
	size_t str_len;
	
	ptr = malloc(sizeof(char) * (str_len + 1));
		if(!ptr)
			return(NULL);
	i = 0;
	while(s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return(ptr);
}

int main()
{
	char str[] = "hello word its me";
	char *ptr = ft_strmapi(str, f);
	printf("%s", ptr);
}

