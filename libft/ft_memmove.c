/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:13:55 by ybecret           #+#    #+#             */
/*   Updated: 2016/12/12 12:39:25 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *tmp;

	tmp = dest;
	if (src > dest)
		dest = ft_memcpy(tmp, src, n);
	if (src < dest)
	{
		src = src + (n - 1);
		tmp = tmp + (n - 1);
		while (n--)
			*tmp-- = *(unsigned char*)src--;
	}
	return (dest);
}
