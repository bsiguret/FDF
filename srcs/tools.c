/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 04:28:29 by bsiguret          #+#    #+#             */
/*   Updated: 2017/12/26 04:52:15 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_newpos			initialisation(t_newpos dot)
{
	t_newpos		ret;

	ret.rx = dot.rx;
	ret.ry = dot.ry;
	ret.rz = dot.rz;
	ret.new_pos_x = dot.new_pos_x;
	ret.new_pos_y = dot.new_pos_y;
	ret.new_init_x = dot.new_init_x;
	ret.new_init_y = dot.new_init_y;
	ret.new_sub_widht = dot.new_sub_widht;
	ret.new_sub_height = dot.new_sub_height;
	ret.grid = dot.grid;
	return (ret);
}

void				reset_func(t_param *setup)
{
	t_image			tmp;

	ft_memdel((void**)setup->nbr);
	ft_memdel((void**)setup->dot);
	ft_memdel((void**)setup->stock);
	setup->nbr = ft_getdata(setup->endl, setup->len, setup->ret);
	setup->dot = get_map(setup->endl, setup->len, setup->nbr);
	setup->stock = get_pos_data(setup->endl, setup->len, setup->dot);
	mlx_destroy_image(setup->mlx, setup->pict.img_ptr);
	tmp.img_ptr = mlx_new_image(setup->mlx, WIDHT + 50, HEIGHT + 50);
	tmp.data = mlx_get_data_addr(tmp.img_ptr, &tmp.bpp,
			&tmp.sizeline, &tmp.endian);
	setup->pict = tmp;
	print_map(setup, setup->color, setup->stock);
	mlx_put_image_to_window(setup->mlx, setup->window, tmp.img_ptr, 0, 120);
}

void				print_menu(void *mlx, void *win)
{
	mlx_string_put(mlx, win, 10, 20, 0xFF0000, "Zoom: [+][-]");
	mlx_string_put(mlx, win, 10, 35, 0xFF0000, "Rotation: [X][Y]");
	mlx_string_put(mlx, win, 10, 50, 0xFF0000, "Move: [UP][DOWN][RIGHT][LEFT]");
	mlx_string_put(mlx, win, 10, 65, 0xFF0000, "Height ratio: [1][2]");
	mlx_string_put(mlx, win, 10, 82, 0xFF0000, "Reset view: [R]");
	mlx_string_put(mlx, win, 10, 99, 0xFF0000, "Exit: [ESC]");
}

void				put_pixel(t_param *s, unsigned long c, int x, int y)
{
	unsigned int	rt;

	rt = mlx_get_color_value(s->mlx, c);
	s->pict.data[y * s->pict.sizeline + x * s->pict.bpp / 8] = (rt & 0xFF);
	s->pict.data[y * s->pict.sizeline + x * s->pict.bpp / 8 + 1] = (
			rt & 0xFF00) >> 8;
	s->pict.data[y * s->pict.sizeline + x * s->pict.bpp / 8 + 2] = (
			rt & 0xFF0000) >> 16;
}
