/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 21:42:59 by bsiguret          #+#    #+#             */
/*   Updated: 2017/12/26 05:19:59 by bsiguret         ###   ########.fr       */
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

static void		param_init(t_param *setup, char *file)
{
	setup->ret = read_file(file);
	if (check_file(setup->ret) == 0)
	{
		ft_putendl_fd("Error, bad size of some line in file!", 2);
		exit(EXIT_FAILURE);
	}
	setup->endl = nb_line(setup->ret);
	setup->len = size_line((setup->ret)[0]);
	setup->mlx = mlx_init();
	setup->nbr = ft_getdata(setup->endl, setup->len, setup->ret);
	setup->dot = get_map(setup->endl, setup->len, setup->nbr);
	setup->window = mlx_new_window(setup->mlx, WIDHT, HEIGHT, "FDF");
	setup->pict = image_init(setup->mlx);
	setup->stock = get_pos_data(setup->endl, setup->len, setup->dot);
	setup->color = get_color_data(setup->endl, setup->len, setup->dot,
			setup->ret);
}

static void		do_event(int key, t_param *setup)
{
	t_image		tmp;
	t_newpos	**newstock;

	mlx_destroy_image(setup->mlx, setup->pict.img_ptr);
	newstock = get_pos_event_data(setup->endl, setup->len, setup->stock, key);
	tmp.img_ptr = mlx_new_image(setup->mlx, WIDHT + 50, HEIGHT + 50);
	tmp.data = mlx_get_data_addr(tmp.img_ptr, &tmp.bpp,
			&tmp.sizeline, &tmp.endian);
	setup->pict = tmp;
	print_map(setup, setup->color, newstock);
	mlx_put_image_to_window(setup->mlx, setup->window, tmp.img_ptr, 0, 120);
	ft_memdel((void**)setup->stock);
	setup->stock = newstock;
}

static int		my_function(int key, t_param *setup)
{
	if (key == KEY_EXIT)
		exit(0);
	if (key == RESET)
		reset_func(setup);
	else if (key == KEY_RIGHT || key == KEY_LEFT || key == KEY_UP ||
			key == KEY_DOWN || key == KEY_ZOOM_IN || key == KEY_ZOOM_OUT
			|| key == KEY_ROT || key == KEY_ROT_Y || key == ADD_HEIGHT
			|| key == RM_HEIGHT)
		do_event(key, setup);
	return (0);
}

int				main(int ac, char **av)
{
	t_param		set;

	if (ac != 2 || ft_strcmp(av[1], "/dev/null") == 0)
	{
		ft_putendl("Error, bad numbers of arguments or not valid argument!");
		return (EXIT_FAILURE);
	}
	param_init(&set, av[1]);
	print_menu(set.mlx, set.window);
	print_map(&set, set.color, set.stock);
	mlx_put_image_to_window(set.mlx, set.window, set.pict.img_ptr, 0, 120);
	mlx_hook(set.window, 2, 3, my_function, &set);
	mlx_loop(set.mlx);
	ft_memdel((void**)&set);
	return (0);
}
