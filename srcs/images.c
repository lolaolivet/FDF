/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:24:53 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/07 19:10:12 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reload_image(t_fdf *d)
{
	mlx_destroy_image(d->mlx_ptr, d->img_ptr);
	new_image(d, d->img_w, d->img_h);
}

void	destroy_exit(t_fdf *d)
{
	mlx_destroy_image(d->mlx_ptr, d->img_ptr);
	free(d->pos);
	free(d->coord);
	exit(-1);
}

void	new_image(t_fdf *d, int w, int h)
{
	int		bpp;
	int		s_l;
	int		endian;

	d->img_ptr = mlx_new_image(d->mlx_ptr, w, h);
	d->img_string = mlx_get_data_addr(d->img_ptr, &(bpp), &(s_l), &(endian));
}

void	fill_pixel(t_fdf *d, int x, int y, int color)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = (color & 0xff0000) >> 16;
	green = (color & 0xff00) >> 8;
	blue = (color & 0xff);
	d->img_string[(y * d->img_w * 4) + (x * 4)] = blue;
	d->img_string[(y * d->img_w * 4) + (x * 4) + 1] = green;
	d->img_string[(y * d->img_w * 4) + (x * 4) + 2] = red;
}
