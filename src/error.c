/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:20:32 by bsiguret          #+#    #+#             */
/*   Updated: 2017/12/09 17:46:59 by bsiguret         ###   ########.fr       */
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
