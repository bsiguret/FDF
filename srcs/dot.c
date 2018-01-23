/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 07:27:49 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/23 18:10:24 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point		*get_line(int size, int index, int *alpha)
{
	t_point		*nbr;
	int			i;

	i = 0;
	nbr = (t_point*)malloc(sizeof(t_point) * (size + 1));
	while (i < size - 1)
	{
		nbr[i].x = i;
		nbr[i].y = index;
		nbr[i].z = alpha[i];
		i++;
	}
	return (nbr);
}

t_point				**get_map(int endl, int len, int **alpha)
{
	t_point		**ret;
	int			index;

	index = 0;
	ret = (t_point**)malloc(sizeof(t_point*) * (endl + 1));
	while (index < endl)
	{
		ret[index] = get_line(len, index, alpha[index]);
		index++;
	}
	return (ret);
}

static t_newpos		dot_in_win(int size, t_point dot)
{
	t_newpos		ret;

	ret.rx = dot.x;
	ret.ry = dot.y;
	ret.rz = dot.z;
	ret.new_pos_x = INIT_X + ((SUB_WIDTH / (size - 1)) * dot.x);
	ret.new_pos_y = INIT_Y + ((SUB_HEIGHT / (size - 1)) * dot.y) - ((SUB_HEIGHT
				/ (size - 1)) * dot.z);
	ret.new_init_x = INIT_X;
	ret.new_init_y = INIT_Y;
	ret.new_sub_widht = SUB_WIDTH;
	ret.new_sub_height = SUB_HEIGHT;
	ret.grid = INIT_GRID;
	return (ret);
}

static void			get_pos_endl(t_param *d, int i)
{
	int				index;

	index = 0;
	while (index < d->len)
	{
		d->stock[i][index] = dot_in_win(d->len, d->dot[i][index]);
		index++;
	}
}

void				get_pos_data(t_param *d)
{
	int				index;

	index = 0;
	while (index < d->endl)
	{
		get_pos_endl(d, index);
		index++;
	}
}
