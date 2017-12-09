/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:46:38 by bsiguret          #+#    #+#             */
/*   Updated: 2017/12/09 17:26:18 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../Minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_point
{
	int							x;
	int							y;
	int							z;
	struct s_point	*next;
}									t_point;

typedef struct		s_fdf
{
	void						*win;
	void						*mlx;
	t_point					point;
}									t_fdf;

int								nb_line(char *map);

/* ERROR FUNCTION */
void							arg_error(void);
void							map_error(void);
#endif
