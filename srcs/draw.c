/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 04:30:38 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/26 13:37:45 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_draw	init(t_newpos d1, t_newpos d2)
{
	t_draw		ret;

	ret.dx = abs(d2.new_pos_x - d1.new_pos_x);
	ret.sx = d1.new_pos_x < d2.new_pos_x ? 1 : -1;
	ret.dy = abs(d2.new_pos_y - d1.new_pos_y);
	ret.sy = d1.new_pos_y < d2.new_pos_y ? 1 : -1;
	ret.err = (ret.dx > ret.dy ? ret.dx : -ret.dy) / 2;
	ret.e2 = 0;
	return (ret);
}

static int		check_positions(int x, int y)
{
	if ((x > WIDHT || x <= 0 || y > HEIGHT || y <= 0))
		return (1);
	else
		return (0);
}

static void		draw_line(t_param *d, unsigned long c, t_newpos d1, t_newpos d2)
{
	t_draw		tmp;

	tmp = init(d1, d2);
	while (1)
	{
		if (!check_positions(d1.new_pos_x, d1.new_pos_y))
			put_pixel(d, c, d1.new_pos_x, d1.new_pos_y);
		if (d1.new_pos_x == d2.new_pos_x &&
				d1.new_pos_y == d2.new_pos_y)
			break ;
		tmp.e2 = tmp.err;
		if (tmp.e2 > -tmp.dx)
		{
			tmp.err -= tmp.dy;
			d1.new_pos_x += tmp.sx;
		}
		if (tmp.e2 < tmp.dy)
		{
			tmp.err += tmp.dx;
			d1.new_pos_y += tmp.sy;
		}
	}
}

static void		last_line(t_param *d, int x, unsigned long **c, t_newpos **data)
{
	int y;

	y = 0;
	while (y < d->len - 1)
	{
		draw_line(d, c[x][y], data[x][y], data[x][y]);
		if (y < d->len - 2)
		{
			if (data[x][y].rz <= data[x][y + 1].rz)
				draw_line(d, c[x][y + 1], data[x][y], data[x][y + 1]);
			else
				draw_line(d, c[x][y], data[x][y], data[x][y + 1]);
		}
		y++;
	}
}

void			print_map(t_param *d, unsigned long **color, t_newpos **data)
{
	int			x;
	int			y;

	x = 0;
	while (x < d->endl - 1)
	{
		y = 0;
		while (y < d->len - 1)
		{
			if (data[x][y].rz <= data[x + 1][y].rz)
				draw_line(d, color[x + 1][y], data[x][y], data[x + 1][y]);
			else
				draw_line(d, color[x][y], data[x][y], data[x + 1][y]);
			if (y < d->len - 2)
			{
				if (data[x][y].rz <= data[x][y + 1].rz)
					draw_line(d, color[x][y + 1], data[x][y], data[x][y + 1]);
				else
					draw_line(d, color[x][y], data[x][y], data[x][y + 1]);
			}
			y++;
		}
		x++;
	}
	last_line(d, x, color, data);
}
