/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:18:31 by lolivet           #+#    #+#             */
/*   Updated: 2018/03/28 18:48:33 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *str)
{
	ft_puterror(str);
	exit(0);
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
		if ((fd = open(file, O_RDONLY)) == -1 && argc != 2)
			ft_error(strerror(errno));
		else
			return (fd);
	}
	else
		ft_error("Not a valid file");
	return (0);
}

void	init_map(t_fdf *d)
{
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
		ft_htoi(argv[2], &res, 0, 0);
		d->color = res;
		d->img_h = IMG_H;
		d->img_w = IMG_W;
	}
	else if (argc == 5)
	{
		ft_htoi(argv[2], &res, 0, 0);
		d->color = res;
		d->img_w = ft_atoi(argv[3]);
		d->img_h = ft_atoi(argv[4]);
	}
	else
	{
		d->color = 0xffffff;
		d->img_h = IMG_H;
		d->img_w = IMG_W;
	}
}

int		main(int argc, char **argv)
{
	t_fdf	data;

	if (argc < 2 || argc > 5 || argc == 4)
		ft_error("Wrong number of argument");
	if (!(data.coord = (int **)ft_memalloc(sizeof(int *) * 2))
			|| !(data.coord[0] = (int *)ft_memalloc(sizeof(int) * 2))
			|| !(data.coord[1] = (int *)ft_memalloc(sizeof(int) * 2)))
		ft_error(strerror(errno));
	data.fd = open_file(argv[1], argc);
	data.fd2 = open_file(argv[1], argc);
	parse_file(&data, 0, 0, 0);
	init_arg(&data, argc, argv);
	init_map(&data);
	draw_grid(&data);
	mlx_key_hook(data.win_ptr, deal_key, (void *)&data);
	mlx_loop(data.mlx_ptr);
}