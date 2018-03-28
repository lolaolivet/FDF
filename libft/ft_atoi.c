/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:46:10 by lolivet           #+#    #+#             */
/*   Updated: 2018/03/25 18:34:30 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((str[i] >= 0 && str[i] <= 20) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		neg = (str[i] == '-') ? -1 : 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = str[i] - '0' + res;
		i++;
	}
	return (neg * (res));
}
