/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:28:52 by ybecret           #+#    #+#             */
/*   Updated: 2016/12/17 19:07:30 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int res;
	int nega;
	int i;

	i = 0;
	nega = 1;
	while (ft_iswhitespace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i++] == '-')
			nega = -1;
	}
	res = 0;
	while (s[i] && ft_isdigit(s[i]))
	{
		res += s[i] - 48;
		if (ft_isdigit(s[i + 1]))
			res *= 10;
		i++;
	}
	return (res * nega);
}
