/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 14:37:27 by ybecret           #+#    #+#             */
/*   Updated: 2016/12/17 17:43:00 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;
	t_list *tmp1;

	if (!lst || !f)
		return (NULL);
	tmp1 = (*f)(lst);
	if ((new = ft_lstnew(tmp1->content, tmp1->content_size)) == NULL)
		return (NULL);
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		tmp1 = (*f)(lst);
		if ((tmp->next = ft_lstnew(tmp1->content, tmp1->content_size)) == NULL)
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}
