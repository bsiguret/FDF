/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:28:51 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/24 16:29:35 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	is_mapvalid(char *l)
{
	while (*l)
	{
		while (*l && *l == ' ')
			l++;
		if (*l == '-')
			l++;
		if (!*l || (*l < '0' || *l > '9'))
			map_error();
		while (*l && ft_isdigit(*l))
			l++;
		if (*l && *l == ',')
		{
			l += is_hexvalid(l);
			if (*l && *l != ' ')
				map_error();
		}
		if (*l == '\0')
			break ;
		while (*l && *l == ' ')
			l++;
	}
	if (*l)
		map_error();
}

int		is_hexvalid(char *l)
{
	int i;

	i = 0;
	l++;
	if (*l && *l != '0')
		map_error();
	l++;
	if (*l && *l != 'x')
		map_error();
	l++;
	while (*l != ' ')
	{
		if ((*l < '0' || *l > '9') && (*l < 'A' || *l > 'F') &&
				(*l < 'a' || *l > 'f'))
			map_error();
		l++;
		i++;
	}
	if (i == 0)
		map_error();
	return (i + 3);
}