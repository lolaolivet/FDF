/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:28:59 by lolivet           #+#    #+#             */
/*   Updated: 2018/03/25 23:15:12 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_hexa(char *str, t_htoi *h)
{
	if (str[1] == 'x' || str[1] == 'X')
	{
		h->msnibble = 2;
		h->digits = ft_strlen(str) - 2;
	}
	else
	{
		h->msnibble = 0;
		h->digits = ft_strlen(str);
	}
}

int		ft_htoi(char *str, int *result, int c, int i)
{
	t_htoi	h;

	if (result == NULL)
		return (-1);
	if (str[0] == '0')
		parse_hexa(str, &h);
	if (h.digits > 16 || h.digits == 0)
		return (-1);
	*result = 0;
	while ((c = str[i + h.msnibble]) != '\0')
	{
		if (c >= 'a' && c <= 'f')
			c = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			c = c - 'A' + 10;
		else if (c >= '0' && c <= '9')
			c -= '0';
		else
			return (-1);
		i++;
		*result = *result << 4 | c;
	}
	return (0);
}
