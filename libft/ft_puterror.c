/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:58:43 by lolivet           #+#    #+#             */
/*   Updated: 2018/03/25 20:04:52 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_error(char c)
{
	write(2, &c, 1);
}

void	ft_puterror(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write_error(str[i]);
		i++;
	}
	write_error('\n');
}
