/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:25:20 by lolivet           #+#    #+#             */
/*   Updated: 2018/03/28 18:18:23 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_points(t_fdf *d, int i, int j, int k)
{
	if (!(d->p = (t_tab*)ft_memalloc(sizeof(t_tab) * d->size_p)))
		ft_error(strerror(errno));
	while (i < d->nb_line)
	{
		while (j < d->nb_col)
		{
			if (d->pos[i][j] > 0 || d->pos[i][j] < 0)
			{
				d->p[k][0] = i;
				d->p[k][1] = j;
				k++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	fill_position(t_fdf *d, char **p, int i, int j)
{
	char	**tmp;

	if (!(d->pos = (int **)ft_memalloc(sizeof(int *) * d->nb_line)))
		ft_error(strerror(errno));
	while (i < d->nb_line)
	{
		if (!(d->pos[i] = (int *)ft_memalloc(sizeof(int) * d->nb_col)))
			ft_error(strerror(errno));
		tmp = ft_strsplit(p[i], ' ');
		ft_strdel(&(p[i]));
		while (j < d->nb_col)
		{
			d->pos[i][j] = ft_atoi(tmp[j]);
			ft_strdel(&(tmp[j]));
			if (d->pos[i][j] < 0 || d->pos[i][j] > 0)
				(d->size_p)++;
			j++;
		}
		free(tmp);
		j = 0;
		i++;
	}
	if (d->size_p)
		fill_points(d, 0, 0, 0);
	free(p);
}

void	parse_file(t_fdf *d, int i, int j, int k)
{
	char	*line;
	char	**tmp;
	char	**p;

	d->nb_line = 0;
	while ((i = get_next_line(d->fd, &line)))
	{
		(d->nb_line)++;
		ft_strdel(&line);
	}
	i = 0;
	if (!(p = (char **)ft_memalloc(sizeof(char *) * d->nb_line)))
		ft_error(strerror(errno));
	while ((i = get_next_line(d->fd2, &line)))
	{
		j = 0;
		tmp = ft_strsplit(line, ' ');
		while (tmp[j])
			ft_strdel(&(tmp[j++]));
		free(tmp);
		p[k] = line;
		k++;
	}
	d->nb_col = j;
	fill_position(d, p, 0, 0);
}
