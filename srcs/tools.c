/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 04:28:29 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/23 17:29:43 by bsiguret         ###   ########.fr       */
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

void				reset_func(t_param *d)
{
	t_image			tmp;

	d->nbr = ft_getdata(d->endl, d->len, d->ret);
	d->dot = get_map(d->endl, d->len, d->nbr);
	get_pos_data(d);
	mlx_destroy_image(d->mlx, d->pict.img_ptr);
	tmp.img_ptr = mlx_new_image(d->mlx, WIDHT + 50, HEIGHT + 50);
	tmp.data = mlx_get_data_addr(tmp.img_ptr, &tmp.bpp,
			&tmp.sizeline, &tmp.endian);
	d->pict = tmp;
	print_map(d, d->color, d->stock);
	mlx_put_image_to_window(d->mlx, d->window, tmp.img_ptr, 0, 130);
}

void				print_menu(void *mlx, void *win)
{
	mlx_string_put(mlx, win, 10, 5, 0xFF0000, "Exit: [ESC]");
	mlx_string_put(mlx, win, 10, 25, 0xFF0000, "Move: [UP][DOWN][RIGHT][LEFT]");
	mlx_string_put(mlx, win, 10, 45, 0xFF0000, "Zoom: [-][+]");
	mlx_string_put(mlx, win, 10, 65, 0xFF0000, "Height ratio: [1][2]");
	mlx_string_put(mlx, win, 10, 85, 0xFF0000, "Reset view: [R]");
	mlx_string_put(mlx, win, 10, 105, 0xFF0000, "Rotation: [X][Y]");
}

void				put_pixel(t_param *d, unsigned long c, int x, int y)
{
	unsigned int	rt;

	rt = mlx_get_color_value(d->mlx, c);
	d->pict.data[y * d->pict.sizeline + x * d->pict.bpp / 8] = (rt & 0xFF);
	d->pict.data[y * d->pict.sizeline + x * d->pict.bpp / 8 + 1] = (
			rt & 0xFF00) >> 8;
	d->pict.data[y * d->pict.sizeline + x * d->pict.bpp / 8 + 2] = (
			rt & 0xFF0000) >> 16;
}

void				ft_freeret(char **ret)
{
	int	i;

	i = 0;
	while(ret[i])
		free(ret[i++]);
	free(ret);
}