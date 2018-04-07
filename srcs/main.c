/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:18:31 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/07 19:07:38 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		verify_arg(char *width, char *height)
{
	int		w;
	int		h;

	if ((w = ft_atoi(width)))
	{
		if ((h = ft_atoi(height)) && ((w <= 2500 && h <= 1300)
					&& (w >= 100 && h >= 100)))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int		open_file(char *file, int argc)
{
	int		fd;
	int		i;
	char	*ext;

	i = 0;
	ext = ".fdf";
	if (ft_strstr(file, ext))
	{
		if (!(fd = open(file, O_RDONLY)) || fd == -1 || argc < 2)
			ft_error(strerror(errno));
		else
			return (fd);
	}
	else
		ft_error(strerror(errno));
	return (0);
}

void	init_map(t_fdf *d, int argc)
{
	if (argc == 2)
	{
		d->color = 0xffffff;
		d->img_h = IMG_H;
		d->img_w = IMG_W;
	}
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->img_w, d->img_h, "FDF");
	new_image(d, d->img_w, d->img_h);
	if (d->img_h / d->nb_line < d->img_w / d->nb_line)
	{
		d->t_h = (d->img_h / d->nb_line) / 2;
		d->t_w = (d->img_h / d->nb_line) / 2;
	}
	else
	{
		d->t_h = (d->img_w / d->nb_col) / 2;
		d->t_w = (d->img_w / d->nb_col) / 2;
	}
	d->x_i = (d->img_w - (d->t_w * d->nb_col)) / 2;
	d->y_i = (d->img_h - (d->t_h * d->nb_line)) / 2;
	d->ud = 0;
	d->rl = 0;
	d->a = 0;
}

void	init_arg(t_fdf *d, int argc, char **argv)
{
	int		res;

	if (argc == 3)
	{
		if (ft_htoi(argv[2], &res, 0, 0))
		{
			d->color = res;
			d->img_h = IMG_H;
			d->img_w = IMG_W;
		}
		else
			ft_error("Not an hexadecimal number");
	}
	if (argc == 5)
	{
		if (ft_htoi(argv[2], &res, 0, 0) && verify_arg(argv[3], argv[4]))
		{
			d->color = res;
			d->img_w = ft_atoi(argv[3]);
			d->img_h = ft_atoi(argv[4]);
		}
		else
			ft_error("Not a number, number too big or negative");
	}
}

int		main(int argc, char **argv)
{
	t_fdf	data;

	ft_bzero(&data, sizeof(t_fdf));
	if (argc < 2 || argc > 5 || argc == 4)
		ft_error("Wrong number of argument");
	if (!(data.coord = (int **)ft_memalloc(sizeof(int *) * 2))
			|| !(data.coord[0] = (int *)ft_memalloc(sizeof(int) * 2))
			|| !(data.coord[1] = (int *)ft_memalloc(sizeof(int) * 2)))
		ft_error(strerror(errno));
	parse_file(&data, argv[1]);
	init_arg(&data, argc, argv);
	init_map(&data, argc);
	draw_grid(&data);
	mlx_hook(data.win_ptr, 2, (1L << 0), &deal_key, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
