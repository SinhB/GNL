/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 14:19:25 by ybecret           #+#    #+#             */
/*   Updated: 2016/12/19 20:18:34 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_newlen(char *s, char c)
{
	size_t n;

	while (*s && *s == c)
		s++;
	n = (*s ? 1 : 0);
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
			n++;
		s++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	n;
	char	*tmp;
	char	**new;

	if (!s)
		return (NULL);
	n = ft_newlen((char*)s, c);
	if ((new = (char**)malloc(sizeof(char*) * (n + 1))) == NULL)
		return (NULL);
	tmp = (char*)s;
	while (*s)
	{
		if (*s == c)
		{
			if (tmp != s)
				*(new++) = ft_strsub(tmp, 0, s - tmp);
			tmp = (char*)s + 1;
		}
		s++;
	}
	if (tmp != s)
		*(new++) = ft_strsub(tmp, 0, s - tmp);
	*new = NULL;
	return (new - n);
}
