/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:34:56 by lolivet           #+#    #+#             */
/*   Updated: 2018/03/29 22:40:47 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_coord(t_fdf *d)
{
	int		x;
	int		y;
	int		k;

	x = 0;
	y = 0;
	k = 0;
	if ((d->coord[0][0] >= 0 && d->coord[0][0] < d->img_w)
			&& (d->coord[1][0] >= 0 && d->coord[1][0] < d->img_w)
			&& (d->coord[0][1] >= 0 && d->coord[0][1] < d->img_h)
			&& (d->coord[1][1] >= 0 && d->coord[1][1] < d->img_h))
		draw_line(d);
}

void	draw_x(t_fdf *d)
{
	int		x;
	int		y;
	int		z;

	x = d->x_i + ((d->x + d->rl) * d->t_h);
	y = d->y_i + ((d->y + d->ud) * d->t_w);
	z = d->pos[d->y][d->x];
	d->coord[0][0] = (x * cos(d->a)) + (y * -sin(d->a)) - z;
	d->coord[0][1] = (x * sin(d->a)) + (y * cos(d->a)) - z;
	x = d->x_i + ((d->x + 1 + d->rl) * d->t_h);
	y = d->y_i + ((d->y + d->ud) * d->t_w);
	z = d->pos[d->y][d->x + 1];
	d->coord[1][0] = (x * cos(d->a)) + (y * -sin(d->a)) - z;
	d->coord[1][1] = (x * sin(d->a)) + (y * cos(d->a)) - z;
	check_coord(d);
}

void	draw_y(t_fdf *d)
{
	int		x;
	int		y;
	int		z;

	x = d->x_i + ((d->x + d->rl) * d->t_h);
	y = d->y_i + ((d->y + d->ud) * d->t_w);
	z = d->pos[d->y][d->x];
	d->coord[0][0] = (x * cos(d->a)) + (y * -sin(d->a)) - z;
	d->coord[0][1] = (x * sin(d->a)) + (y * cos(d->a)) - z;
	x = d->x_i + ((d->x + d->rl) * d->t_h);
	y = d->y_i + ((d->y + 1 + d->ud) * d->t_w);
	z = d->pos[d->y + 1][d->x];
	d->coord[1][0] = (x * cos(d->a)) + (y * -sin(d->a)) - z;
	d->coord[1][1] = (x * sin(d->a)) + (y * cos(d->a)) - z;
	check_coord(d);
}

void	draw_grid(t_fdf *d)
{
	d->x = 0;
	d->y = 0;
	while (d->y < d->nb_line)
	{
		while (d->x < d->nb_col)
		{
			if (d->x != d->nb_col - 1)
				draw_x(d);
			if (d->y != d->nb_line - 1)
				draw_y(d);
			d->x++;
		}
		d->x = 0;
		d->y++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, IMG_X, IMG_Y);
}
