/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:05:56 by bsiguret          #+#    #+#             */
/*   Updated: 2017/12/11 01:44:54 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int		nb_lines(char *map)
{
	int		fd;
	int		nblines;
	char	buf;

	nblines = 0;
	if((fd = open(map, O_RDONLY)) < 0)
		map_error();
	while(read(fd, &buf, 1))
	{
		if(buf == '\n')
			nblines++;
		if((buf != ' ' && buf != '-') || (buf < '0' && buf > '9'))
			map_error();
		buf++;
	}
	close(fd);
	return(nblines);
}

/*int		get_point(char *str)
{
	int	nb;
	int	neg;

	if (*str == '-')
		*str++, neg = 1;
	nb = 0;
	while (*str >= '0'&& *str <= '9')
	{



}*/
