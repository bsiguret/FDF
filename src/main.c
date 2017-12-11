/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:16:02 by bsiguret          #+#    #+#             */
/*   Updated: 2017/12/11 01:44:23 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_funct(int keycode, t_fdf *data)
{
	if (keycode == 12)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int		main(int ac, char **av)
{
	if(ac != 2)
			arg_error();
	printf("Nombre de lignes: %d\n", nb_lines(av[1]));
	return (0);
}
