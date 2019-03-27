/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:21:31 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/09 15:30:01 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# define WIN_H 1000
# define WIN_W 1200
# define IMG_H 1200
# define IMG_W 1200
# define IMG_X 0
# define IMG_Y 0

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
	int			cumul;
	int			x;
	int			y;
}				t_line;

typedef int		t_tab[2];

typedef struct	s_fdf
{
	int			nb_line;
	int			nb_col;
	int			**coord;
	int			**pos;
	t_tab		*p;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_string;
	int			x;
	int			y;
	int			ud;
	int			rl;
	int			size_p;
	int			t_h;
	int			t_w;
	float		a;
	int			img_h;
	int			img_w;
	int			x_i;
	int			y_i;
	int			color;
	char		**tmp;
}				t_fdf;

void			parse_file(t_fdf *d, char *filename);
void			draw_grid(t_fdf *d);
void			draw_line(t_fdf *d);
void			fill_pixel(t_fdf *d, int x, int y, int color);
void			new_image(t_fdf *d, int w, int h);
int				deal_key(int keycode, void *param);
void			reload_image(t_fdf *d);
void			destroy_exit(t_fdf *d);
void			change_pos(t_fdf *d, int key, int i);
void			move_map(t_fdf *d, int key);
void			scale(t_fdf *d, int key);
void			ft_error(char *str);
void			check_entry(char *tmp);

#endif
