/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:06:47 by lolivet           #+#    #+#             */
/*   Updated: 2018/03/28 18:18:46 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Fleche du haut (126) -> deplace vers le haut OK
** Fleche du bas (125) -> vers le bas OK
** Fleche droite (124) -> vers la droite OK
** Fleche gauche (123) -> vers la gauche OK
** Q (12) -> Rotation
** W (13) -> Rotation
** Z (6) -> ++ Hauteur OK
** X (7) -> -- Hauteur OK
** + (24) -> Zoom avant OK
** - (27) -> Zoom arriere OK
*/

#include "fdf.h"

void	scale(t_fdf *d, int key)
{
	int		neg;

	reload_image(d);
	neg = 0;
	neg = (key == 24) ? 0 : 1;
	if (neg && (d->t_h / 2 > 0 && d->t_w / 2 > 0))
	{
		d->t_h -= 2;
		d->t_w -= 2;
	}
	else if (!(neg) && (d->t_h * 2 < 512 && d->t_w * 2 < 512))
	{
		d->t_h += 2;
		d->t_w += 2;
	}
	draw_grid(d);
}

void	move_map(t_fdf *d, int key)
{
	reload_image(d);
	if (key == 126)
		d->ud--;
	if (key == 125)
		d->ud++;
	if (key == 124)
		d->rl++;
	if (key == 123)
		d->rl--;
	draw_grid(d);
}

void	change_pos(t_fdf *d, int key, int i)
{
	int		neg;
	int		j;
	int		k;

	neg = 0;
	j = 0;
	k = 0;
	reload_image(d);
	neg = (key == 6) ? 0 : 1;
	while (i < d->nb_line)
	{
		while (j < d->nb_col && k < d->size_p)
		{
			if ((i == d->p[k][0] && j == d->p[k][1]))
			{
				neg ? d->pos[i][j]-- : d->pos[i][j]++;
				k++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	draw_grid(d);
}

void	rotate(t_fdf *d, int key)
{
	reload_image(d);
	if (key == 12 || key == 13)
		d->a = (key == 13) ? d->a - 0.1 : d->a + 0.1;
	draw_grid(d);
}

int		deal_key(int keycode, void *param)
{
	(void)param;
	if (keycode == 126 || keycode == 125 || keycode == 124
			|| keycode == 123)
		move_map((t_fdf *)param, keycode);
	if (keycode == 6 || keycode == 7)
		change_pos((t_fdf *)param, keycode, 0);
	if (keycode == 24 || keycode == 27)
		scale((t_fdf *)param, keycode);
	if (keycode == 12 || keycode == 13)
		rotate((t_fdf *)param, keycode);
	if (keycode == 53)
		destroy_exit((t_fdf *)param);
	return (0);
}
