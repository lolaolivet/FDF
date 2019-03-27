/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 00:01:49 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/09 15:33:00 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_entry(char *tmp)
{
	int		i;

	i = 0;
	while (tmp[i])
	{
		if (((tmp[i] == '-' || tmp[i] == '+') && (tmp[i + 1] >= '0' &&
						tmp[i + 1] <= '9')) || (tmp[i] >= '0' &&
						tmp[i] <= '9'))
			i++;
		else
			ft_error("Not a valid map");
	}
}

void	ft_error(char *str)
{
	ft_puterror(str);
	exit(0);
}
