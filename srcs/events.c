/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 05:10:01 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/24 14:36:08 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		get_pos_event_endl(t_param *d, int i, int key)
{
	int			index;

	index = 0;
	while (index < d->len)
	{
		if (key == KEY_RIGHT || key == KEY_LEFT ||
				key == KEY_UP || key == KEY_DOWN)
			d->stock[i][index] = new_pos_after_basic_move(d->stock[i][index], key);
		if (key == ADD_HEIGHT || key == RM_HEIGHT)
			d->stock[i][index] = add_size(key, d->len, d->stock[i][index]);
		if (key == KEY_ZOOM_IN || key == KEY_ZOOM_OUT)
			d->stock[i][index] = new_pos_after_zoom(d->len, d->stock[i][index], key);
		if (key == KEY_ROT || key == KEY_ROT_Y)
			d->stock[i][index] = new_pos_after_rotation(d->len, d->stock[i][index], key);
		index++;
	}
}

void			get_pos_event_data(t_param *d, int key)
{
	int			index;

	index = 0;
	while (index < d->endl)
	{
		get_pos_event_endl(d, index, key);
		index++;
	}
}

void			ft_getdata(t_param *d, char **stock)
{
	int		index;

	index = 0;
	while (index < d->endl)
	{
		ft_getnbr(d->nbr[index], d->len, *stock);
		index++;
		stock++;
	}
}

void			ft_freenewpos(t_newpos **stock)
{
	int	i;

	i = 0;
	while (stock[i])
		free(stock[i++]);
	free(stock);
}

void			ft_parammalloc(t_param *d)
{
	int	index;

	index = 0;
	d->stock = (t_newpos**)malloc(sizeof(t_newpos*) * (d->endl + 1));
	d->dot = (t_point**)malloc(sizeof(t_point*) * (d->endl + 1));
	d->nbr = (int**)malloc(sizeof(int*) * (d->endl + 1));
	while (index < d->endl)
	{
		d->stock[index] = (t_newpos*)malloc(sizeof(t_newpos) * (d->len + 1));
		d->dot[index] = (t_point*)malloc(sizeof(t_point) * (d->len + 1));
		d->nbr[index] = (int*)malloc(sizeof(int) * d->len + 1);
		index++;
	}
}