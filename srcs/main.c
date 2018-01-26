/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 21:42:59 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/26 13:39:36 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_image	image_init(void *mlx)
{
	t_image		pict;

	pict.img_ptr = mlx_new_image(mlx, WIDHT + 50, HEIGHT + 50);
	pict.data = mlx_get_data_addr(pict.img_ptr, &pict.bpp, &pict.sizeline,
			&pict.endian);
	return (pict);
}

static void		param_init(t_param *d, char *file)
{
	d->ret = read_file(file);
	if (check_file(d->ret) == 0)
	{
		ft_putendl_fd("Error, invalid line size in map file!", 2);
		exit(EXIT_FAILURE);
	}
	d->endl = nb_line(d->ret);
	d->len = size_line((d->ret)[0]);
	d->mlx = mlx_init();
	ft_parammalloc(d);
	ft_getdata(d, d->ret);
	get_map(d, d->endl, d->len, d->nbr);
	d->window = mlx_new_window(d->mlx, WIDHT, HEIGHT, "bsiguret FDF");
	d->pict = image_init(d->mlx);
	get_pos_data(d);
	d->color = get_color_data(d->endl, d->len, d->dot,
			d->ret);
}

static void		do_event(int key, t_param *d)
{
	t_image		tmp;

	mlx_destroy_image(d->mlx, d->pict.img_ptr);
	get_pos_event_data(d, key);
	tmp.img_ptr = mlx_new_image(d->mlx, WIDHT + 50, HEIGHT + 50);
	tmp.data = mlx_get_data_addr(tmp.img_ptr, &tmp.bpp,
			&tmp.sizeline, &tmp.endian);
	d->pict = tmp;
	print_map(d, d->color, d->stock);
	mlx_put_image_to_window(d->mlx, d->window, tmp.img_ptr, 0, 130);
}

static int		my_function(int key, t_param *d)
{
	if (key == KEY_EXIT)
		exit(0);
	if (key == RESET)
		reset_func(d);
	else if (key == KEY_RIGHT || key == KEY_LEFT || key == KEY_UP ||
			key == KEY_DOWN || key == KEY_ZOOM_IN || key == KEY_ZOOM_OUT
			|| key == KEY_ROT || key == KEY_ROT_Y || key == ADD_HEIGHT
			|| key == RM_HEIGHT)
		do_event(key, d);
	return (0);
}

int				main(int ac, char **av)
{
	t_param		*set;
	int			fd;

	fd = open(av[1], O_RDONLY);
	if (ac != 2 || fd < 0)
		map_error();
	if (!(set = (t_param*)malloc(sizeof(t_param))))
		malloc_error();
	param_init(set, av[1]);
	print_menu(set->mlx, set->window);
	print_map(set, set->color, set->stock);
	mlx_put_image_to_window(set->mlx, set->window, set->pict.img_ptr, 0, 130);
	mlx_hook(set->window, 2, 1, my_function, set);
	mlx_loop(set->mlx);
	return (0);
}
