/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:59:48 by lolivet           #+#    #+#             */
/*   Updated: 2018/03/25 18:42:34 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	*tmp;
	size_t	i;

	i = 0;
	if (!size)
		return (NULL);
	tmp = malloc(size);
	if (!tmp)
		return (NULL);
	while (i < size)
	{
		((unsigned char *)tmp)[i] = 0;
		i++;
	}
	return (tmp);
}
