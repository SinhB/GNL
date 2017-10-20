/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:34:05 by ybecret           #+#    #+#             */
/*   Updated: 2016/12/12 12:39:18 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *alloc;

	if ((alloc = (void*)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	ft_bzero(alloc, size);
	return (alloc);
}
