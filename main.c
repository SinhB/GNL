/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 16:42:36 by ybecret           #+#    #+#             */
/*   Updated: 2017/10/18 16:51:52 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int ac, char**av)
{
	char *line;
	int fd;

	if (ac < 2)
	{
		dprintf(1, "Usage %s <filename>\n", av[0]);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		dprintf(1, "%s", line);
	}
	return (0);
}
