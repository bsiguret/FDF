/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 07:27:49 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/26 12:42:16 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			get_line(t_param *d, int size, int index, int *alpha)
{
	int			i;

	i = 0;
	while (i < size - 1)
	{
		d->dot[index][i].x = i;
		d->dot[index][i].y = index;
		d->dot[index][i].z = alpha[i];
		i++;
	}
}

void				get_map(t_param *d, int endl, int len, int **alpha)
{
	int			index;

	index = 0;
	while (index < endl)
	{
		get_line(d, len, index, alpha[index]);
		index++;
	}
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
