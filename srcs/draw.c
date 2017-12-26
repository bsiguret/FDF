/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 04:30:38 by bsiguret          #+#    #+#             */
/*   Updated: 2017/12/26 05:09:24 by bsiguret         ###   ########.fr       */
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

static void		draw_line(t_param *s, unsigned long c, t_newpos d1, t_newpos d2)
{
	t_draw		tmp;

	tmp = init(d1, d2);
	while (1)
	{
		if (!check_positions(d1.new_pos_x, d1.new_pos_y))
			put_pixel(s, c, d1.new_pos_x, d1.new_pos_y);
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

void			print_map(t_param *s, unsigned long **color, t_newpos **data)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (x < s->endl - 1)
	{
		y = 0;
		while (y < s->len - 1)
		{
			if (data[x][y].rz <= data[x + 1][y].rz)
				draw_line(s, color[x + 1][y], data[x][y], data[x + 1][y]);
			else
				draw_line(s, color[x][y], data[x][y], data[x + 1][y]);
			if (y < s->len - 2)
			{
				if (data[x][y].rz <= data[x][y + 1].rz)
					draw_line(s, color[x][y + 1], data[x][y], data[x][y + 1]);
				else
					draw_line(s, color[x][y], data[x][y], data[x][y + 1]);
			}
			y++;
		}
		x++;
	}
}
