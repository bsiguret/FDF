/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:15:09 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/04 21:32:22 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "/Users/bastiensiguret/minilibx/mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/uio.h>

# define WIDHT 1000
# define HEIGHT 800

# define INIT_GRID 1

# define SUB_WIDTH 1500
# define SUB_HEIGHT 860
# define COLOR1 "4286f4"
# define COLOR2 "007B0C"
# define COLOR3 "FFD827"
# define COLOR4 "FF7719"

/*
 * KEY/ZOOMDEFINE
*/

# define INIT_X 200
# define INIT_Y 110

# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_DOWN 65364

# define KEY_ROT 120
# define KEY_ROT_Y 121

# define RESET 114

# define ADD_HEIGHT 50
# define RM_HEIGHT 49

# define KEY_ZOOM_IN 61
# define KEY_ZOOM_OUT 45

# define ROTA 0.05
# define KEY_EXIT 65307

# define LEFT 20
# define RIGHT 20
# define UP 20
# define DOWN 20

# define ZOOM_IN 2
# define ZOOM_OUT 1.9

/*
 * STRUCTURES
*/

typedef struct		s_point
{
	int		x;
	int		y;
	int		z;
}			t_point;

typedef struct		s_image
{
	int		bpp;
	int		endian;
	int		sizeline;
	void		*img_ptr;
	char		*data;
}			t_image;

typedef struct		s_draw
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
}			t_draw;

typedef struct		s_newpos
{
	float		rx;
	float		ry;
	float		rz;
	int		new_pos_x;
	int		new_pos_y;
	float		new_init_x;
	float		new_init_y;
	float		new_sub_widht;
	float		new_sub_height;
	float		grid;
}			t_newpos;

typedef struct		s_param
{
	char		**ret;
	int		endl;
	int		len;
	void		*mlx;
	void		*window;
	int		**nbr;
	t_point		**dot;
	t_image		pict;
	t_newpos	**stock;
	unsigned long	**color;
}			t_param;

/*
 * Calc dot func
*/
t_point			**get_map(int endl, int len, int **alpha);

/*
 * Parser func
*/
char		**read_file(char *file);
int			check_file(char **stock);
int			size_line(char *str);
int			nb_line(char **stock);
char		*remove_prefix(char *str);
char		*clean_str(char *str);
t_newpos		**get_pos_event_data(int endl, int size,
		t_newpos **data, int key);
int			**ft_getdata(int endl, int size, char **stock);

/*
 * Draw func
*/
void			print_map(t_param *s, unsigned long **color,
						t_newpos **data);
t_newpos		add_size(int keycode, int size, t_newpos dot);
t_newpos		**get_pos_data(int endl, int size, t_point **data);
/*
 * Rotation func
*/

t_newpos		new_pos_after_rotation(int sz, t_newpos dot, int key);
/*
 * Color func
*/
unsigned long		**get_color_data(int endl, int size, t_point **alpha,
						char **stock);

/*
 * Other func
*/
t_newpos		new_pos_after_basic_move(t_newpos dot, int keycode);
void			print_menu(void *mlx, void *win);
void			put_pixel(t_param *s, unsigned long color, int x, int y);
void				reset_func(t_param *setup);
t_newpos			initialisation(t_newpos dot);
t_newpos		new_pos_after_zoom(int sz, t_newpos dot, int key);

#endif
