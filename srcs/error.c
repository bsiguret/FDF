/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:12:19 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/26 13:38:27 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_error(void)
{
	write(2, "Map error, check your file\n", 27);
	exit(1);
}

void	arg_error(void)
{
	write(2, "usage: ./fdf input_map\n", 23);
	exit(1);
}

void	malloc_error(void)
{
	write(2, "Malloc Error, invalid file(?)\n", 30);
	exit(1);
}
