/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:25:20 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/07 19:08:17 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_size(t_fdf *d, int j)
{
	if (j != d->nb_col)
		ft_error("Not a valid map");
	return (1);
}

void	fill_points(t_fdf *d, int i, int j, int k)
{
	if (!(d->p = (t_tab*)ft_memalloc(sizeof(t_tab) * d->size_p)))
		ft_error(strerror(errno));
	while (i < d->nb_line)
	{
		while (j < d->nb_col)
		{
			if (d->pos[i][j] != 0)
			{
				d->p[k][0] = i;
				d->p[k][1] = j;
				k++;
			}
			j++;
		}
		check_size(d, j);
		j = 0;
		i++;
	}
}

void	fill_position(t_fdf *d, char **p, int i, int j)
{
	char	**tmp;

	if (!(d->pos = (int **)ft_memalloc(sizeof(int *) * d->nb_line)))
		ft_error(strerror(errno));
	while (++i < d->nb_line)
	{
		if (!(d->pos[i] = (int *)ft_memalloc(sizeof(int) * d->nb_col)))
			ft_error(strerror(errno));
		tmp = ft_strsplit(p[i], ' ');
		ft_strdel(&(p[i]));
		while (++j < d->nb_col && tmp[j])
		{
			d->pos[i][j] = ft_atoi(tmp[j]);
			ft_strdel(&(tmp[j]));
			if (d->pos[i][j] != 0)
				(d->size_p)++;
		}
		free(tmp);
		check_size(d, j);
		j = -1;
	}
	free(p);
	if (d->size_p)
		fill_points(d, 0, 0, 0);
}

void	get_nb_line(t_fdf *d, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(filename, O_RDONLY)) < 0)
		ft_error(strerror(errno));
	d->nb_line = 0;
	d->nb_col = 0;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		(d->nb_line)++;
		ft_strdel(&line);
	}
	if (i < 0)
		ft_error(strerror(errno));
	close(fd);
}

void	parse_file(t_fdf *d, char *filename)
{
	int		fd;
	int		i;
	char	**line;
	int		k;
	char	**tmp;

	get_nb_line(d, filename);
	if (!(line = (char **)ft_memalloc(sizeof(char *) * (d->nb_line + 1))))
		ft_error(strerror(errno));
	if ((fd = open(filename, O_RDONLY)) < 0)
		ft_error(strerror(errno));
	k = 0;
	while ((i = get_next_line(fd, &(line[k]))) > 0)
	{
		tmp = ft_strsplit(line[k++], ' ');
		i = 0;
		while (tmp[i])
			ft_strdel(&(tmp[i++]));
		d->nb_col = i > d->nb_col ? i : d->nb_col;
		free(tmp);
	}
	if (i < 0)
		ft_error(strerror(errno));
	close(fd);
	fill_position(d, line, -1, -1);
}
