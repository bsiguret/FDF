/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 04:28:00 by bsiguret          #+#    #+#             */
/*   Updated: 2017/12/26 05:11:16 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_newpos	zoom_in(int sz, t_newpos dot)
{
	t_newpos	ret;

	ret = initialisation(dot);
	ret.new_sub_widht = dot.new_sub_widht * 1.1;
	ret.new_sub_height = dot.new_sub_height * 1.1;
	ret.new_pos_x = ret.new_init_x + ((ret.new_sub_widht / (sz - 1)) * dot.rx);
	ret.new_pos_y = ret.new_init_y + ((ret.new_sub_height / (sz - 1)) *
			dot.ry) - ((ret.new_sub_height / (sz - 1) * dot.grid) * dot.rz);
	return (ret);
}

static t_newpos	zoom_out(int sz, t_newpos dot)
{
	t_newpos	ret;

	ret = initialisation(dot);
	ret.new_sub_widht = dot.new_sub_widht * 0.70;
	ret.new_sub_height = dot.new_sub_height * 0.70;
	ret.new_pos_x = ret.new_init_x + ((ret.new_sub_widht / (sz - 1)) * dot.rx);
	ret.new_pos_y = ret.new_init_y + ((ret.new_sub_height / (sz - 1)) *
			dot.ry) - ((ret.new_sub_height / (sz - 1) * dot.grid) * dot.rz);
	return (ret);
}

t_newpos		new_pos_after_zoom(int sz, t_newpos dot, int key)
{
	return ((key == KEY_ZOOM_IN) ? zoom_in(sz, dot) : zoom_out(sz, dot));
}

t_newpos		new_pos_after_basic_move(t_newpos dot, int keycode)
{
	t_newpos	ret;

	ret = initialisation(dot);
	if (keycode == KEY_LEFT)
	{
		ret.new_pos_x = dot.new_pos_x + LEFT;
		ret.new_init_x = dot.new_init_x + LEFT;
	}
	if (keycode == KEY_RIGHT)
	{
		ret.new_pos_x = dot.new_pos_x - RIGHT;
		ret.new_init_x = dot.new_init_x - RIGHT;
	}
	if (keycode == KEY_DOWN)
	{
		ret.new_pos_y = dot.new_pos_y - DOWN;
		ret.new_init_y = dot.new_init_y - DOWN;
	}
	if (keycode == KEY_UP)
	{
		ret.new_pos_y = dot.new_pos_y + UP;
		ret.new_init_y = dot.new_init_y + UP;
	}
	return (ret);
}

t_newpos		add_size(int keycode, int size, t_newpos dot)
{
	t_newpos	ret;

	ret = initialisation(dot);
	if (keycode == ADD_HEIGHT)
		ret.grid = dot.grid * 1.3;
	if (keycode == RM_HEIGHT)
		ret.grid = ret.grid * 0.80;
	ret.new_pos_y = ret.new_init_y + (ret.new_sub_height / (size - 1) * ret.ry)
		- ((ret.new_sub_height / (size - 1)) * ret.grid * ret.rz);
	return (ret);
}