/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 22:46:15 by ybecret           #+#    #+#             */
/*   Updated: 2016/12/19 20:14:39 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = ft_strlen(s);
	tmp = (char*)s + i;
	while (i-- && *tmp != c)
		tmp--;
	return (*tmp == c ? tmp : NULL);
}
