/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 21:53:33 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/04 21:31:31 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_newpos	about_x(int sz, t_newpos dot)
{
	t_newpos	ret;

	ret = initialisation(dot);
	ret.rx = dot.rx;
	ret.ry = dot.ry * cos(ROTA) - dot.rz * sin(ROTA);
	ret.rz = dot.ry * sin(ROTA) + dot.rz * cos(ROTA);
	ret.new_pos_x = dot.new_init_x + ((dot.new_sub_widht / (sz - 1)) * dot.rx);
	ret.new_pos_y = dot.new_init_y + ((dot.new_sub_height / (sz - 1)) *
			ret.ry) - (((dot.new_sub_height / (sz - 1))) * dot.grid * ret.rz);
	ret.new_init_x = dot.new_init_x;
	ret.new_init_y = dot.new_init_y;
	ret.new_sub_widht = dot.new_sub_widht;
	ret.new_sub_height = dot.new_sub_height;
	return (ret);
}

static t_newpos	about_y(int sz, t_newpos dot)
{
	t_newpos	ret;

	ret = initialisation(dot);
	ret.rx = dot.rx * cos(ROTA) + dot.rz * sin(ROTA);
	ret.ry = dot.ry;
	ret.rz = -dot.rx * sin(ROTA) + dot.rz * cos(ROTA);
	ret.new_pos_x = dot.new_init_x + ((dot.new_sub_widht / (sz - 1)) * ret.rx);
	ret.new_pos_y = dot.new_init_y + ((dot.new_sub_height / (sz - 1)) *
			ret.ry) - ((dot.new_sub_height / (sz - 1)) * dot.grid * (ret.rz));
	ret.new_init_x = dot.new_init_x;
	ret.new_init_y = dot.new_init_y;
	ret.new_sub_widht = dot.new_sub_widht;
	ret.new_sub_height = dot.new_sub_height;
	return (ret);
}

t_newpos		new_pos_after_rotation(int sz, t_newpos dot, int key)
{
	return ((key == KEY_ROT) ? about_x(sz, dot) : about_y(sz, dot));
}
