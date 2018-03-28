/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:46:03 by lolivet           #+#    #+#             */
/*   Updated: 2018/03/28 17:58:57 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pos_quadrant(t_fdf *d, t_line *l)
{
	int		i;

	l->cumul = l->dx / 2;
	i = 1;
	while (i <= l->dx)
	{
		l->x += l->xinc;
		l->cumul += l->dy;
		if (l->cumul >= l->dx)
		{
			l->cumul -= l->dx;
			l->y += l->yinc;
		}
		fill_pixel(d, l->x, l->y, d->color);
		i++;
	}
}

void	neg_quadrant(t_fdf *d, t_line *l)
{
	int		i;

	l->cumul = l->dy / 2;
	i = 1;
	while (i <= l->dy)
	{
		l->y += l->yinc;
		l->cumul += l->dx;
		if (l->cumul >= l->dy)
		{
			l->cumul -= l->dy;
			l->x += l->xinc;
		}
		fill_pixel(d, l->x, l->y, d->color);
		i++;
	}
}

void	draw_line(t_fdf *d)
{
	t_line	l;

	l.x = d->coord[0][0];
	l.y = d->coord[0][1];
	l.dx = d->coord[1][0] - d->coord[0][0];
	l.dy = d->coord[1][1] - d->coord[0][1];
	l.xinc = (l.dx > 0) ? 1 : -1;
	l.yinc = (l.dy > 0) ? 1 : -1;
	l.dx = abs(l.dx);
	l.dy = abs(l.dy);
	fill_pixel(d, l.x, l.y, d->color);
	if (l.dx > l.dy)
		pos_quadrant(d, &l);
	else
		neg_quadrant(d, &l);
}
