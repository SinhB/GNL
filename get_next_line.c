/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:51:47 by ybecret           #+#    #+#             */
/*   Updated: 2017/05/22 19:34:34 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd		*new_line(const int fd, char *buff, t_fd **flst)
{ 
	t_fd	*new;

	if (!(new = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	new->fd = fd;
	new->buff = ft_strdup(buff);
	if (!(new->buff))
		return (NULL);
	new->next = *flst;
	*flst = new;
	return (new);
}

static t_fd		*fd_tracker(const int fd, t_fd *flst)
{
	while (flst)
	{
		if (flst->fd == fd)
			return (flst);
		flst = flst->next;
	}
	return (NULL);
}

static int		check_elem(int const fd, char *buff, t_fd **flst)
{
	t_fd	*elem;
	char	*tmp;

	elem = fd_tracker(fd, *flst);
	if (!elem)
	{
		if (!(elem = new_line(fd, buff, flst)))
			return (-1);
	}
	else
	{
		if (!(tmp = ft_strjoin(elem->buff, buff)))
			return (-1);
		free(elem->buff);
		elem->buff = tmp;
	}
	if (ft_strfind(elem->buff, '\n') != -1)
		return (1);
	return (0);
}

static char		*line_tracker(int const fd, t_fd *flst)
{
	t_fd	*elem;
	char	*tmp;
	char	*res;
	int     ret;

	res = NULL;

	if (!(elem = fd_tracker(fd, flst)) || !elem->buff)
		return (NULL);
	if ((ret = ft_strfind(elem->buff, '\n')) != -1)
	{
		if (!(res = ft_strsub(elem->buff, 0, ret)))
			return (NULL);
		if (!(tmp = ft_strdup(elem->buff + ret + 1)))
			return (NULL);
		free(elem->buff);
		elem->buff = tmp;
	}
	else
	{
		if (ft_strlen(elem->buff) != 0 && !(res = ft_strdup(elem->buff)))
			return (NULL);
		free(elem->buff);
		elem->buff = NULL;
	}
	return (res);
}

int				get_next_line(int const fd, char **line)
{
	static t_fd	*flst;
	char		buff[BUFF_SIZE + 1];
	int			ret;
	int			end;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		if ((end = check_elem(fd, buff, &flst)) == 1)
		{
			*line = line_tracker(fd, flst);
			return (1);
		}
		if (end == -1)
			return (-1);
	}
	if ((*line = line_tracker(fd, flst)) != NULL)
		return (1);
	return (0);
}
