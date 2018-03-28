/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 03:08:23 by lolivet           #+#    #+#             */
/*   Updated: 2018/02/14 18:09:21 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_count_word(char *str, int i, int nw)
{
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\0')
		{
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' &&
					str[i] != '\0')
			{
				i++;
			}
			nw++;
		}
		else
		{
			i++;
		}
	}
	return (nw);
}

void	ft_count_char(char **tab, char *str, int i, int j)
{
	int		wl;

	wl = 0;
	while (str[i] != '\0')
	{
		while (str[i] > 32 && str[i] < 127)
		{
			wl++;
			i++;
			if (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n' ||
					str[i + 1] == '\0')
			{
				wl++;
				i++;
				tab[j] = (char*)malloc(sizeof(char) * (wl + 1));
				j++;
				wl = 0;
			}
		}
		i++;
	}
}

char	*ft_fill_tab(char **tab, char *str, int i, int j)
{
	int		k;

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\0')
		{
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' &&
					str[i] != '\0')
			{
				tab[j][k] = str[i];
				k++;
				i++;
			}
			tab[j][k] = '\0';
			k = 0;
			j++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (*tab);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		nw;

	nw = ft_count_word(str, 0, 0);
	tab = (char**)malloc(sizeof(char*) * (nw + 1));
	ft_count_char(tab, str, 0, 0);
	ft_fill_tab(tab, str, 0, 0);
	return (tab);
}
