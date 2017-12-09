/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:05:56 by bsiguret          #+#    #+#             */
/*   Updated: 2017/12/09 18:14:52 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_mapvalid(char *map)
{
	int fd;

	fd = open(map, O_RDONLY);
	while(get_next_line(fd, &map) == 1)
	{
		if()
	}
	return (1);
}

int		nb_ligne(char *map)
{
	int		fd;
	int		nblines;
	char	buf;

	nbline = 0;
	if((fd = open(map, O_RDONLY)) < 0)
		map_error();
	while(read(fd, &buf, 1))
	{
		if(buf == '\n')
			nblines++;
		buf++;
	}
	close(fd);
	return(nbline);
}

int		is_linevalid(char *map)
{
	int space;
	int	nb_numb;

	space = 0;
	while(*map)
	{
		while(*map++ == ' ')
			space++;
		if(*map != '-' || (map < '0' || map > '9')
			map_error();
	}

	return(1);
}
