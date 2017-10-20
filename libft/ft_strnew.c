/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:57:46 by ybecret           #+#    #+#             */
/*   Updated: 2016/12/12 12:39:55 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new;

	if ((new = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
