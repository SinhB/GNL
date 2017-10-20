/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 14:22:01 by ybecret           #+#    #+#             */
/*   Updated: 2016/12/19 20:08:47 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lennbr(int n)
{
	size_t i;

	i = 1;
	if (n == -2147483648)
	{
		i += 2;
		n = 147483648;
	}
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n / 10)
		i += ft_lennbr(n / 10);
	return (i);
}

char			*ft_itoa(int n)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	if (!(new = ft_strnew(ft_lennbr(n))))
		return (NULL);
	if (n == 0 || n == -2147483648)
		return (n == 0 ? ft_strdup("0") : ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		new[i++] = '-';
	}
	while (n / j)
		j *= 10;
	j /= 10;
	while (j > 0)
	{
		new[i++] = (n / j % 10 + 48);
		j /= 10;
	}
	new[i] = '\0';
	return (new);
}
