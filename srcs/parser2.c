/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:28:51 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/26 13:46:50 by bsiguret         ###   ########.fr       */
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

/*
**THRASH FUNCTION (NORME)
*/

void	ft_isnbr_color(unsigned long *nbr, t_point *alpha, int count)
{
	if (alpha[count].z <= 0)
		nbr[count] = ft_atoi_base(COLOR1, 16);
	else if (alpha[count].z >= 1 && alpha[count].z <= 8)
		nbr[count] = ft_atoi_base(COLOR2, 16);
	else if (alpha[count].z >= 9 && alpha[count].z <= 14)
		nbr[count] = ft_atoi_base(COLOR3, 16);
	else
		nbr[count] = ft_atoi_base(COLOR4, 16);
}

int		ft_isread_file(int fd, int count)
{
	char	*line;

	while (get_next_line((int const)fd, &line))
	{
		is_mapvalid(line);
		free(line);
		count++;
	}
	return (count + 1);
}
