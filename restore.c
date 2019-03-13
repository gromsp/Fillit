/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:43:19 by adoyle            #+#    #+#             */
/*   Updated: 2019/03/01 16:43:28 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		**rtrrestore(int **rtr, int i, int d, int n)
{
	while (i < d * d)
	{
		ft_bzeroint(rtr[i], n);
		i++;
	}
	return (rtr);
}

char	*ft_restore(char **str, t_tetro *tetro, int i)
{
	int		j;
	int		tet;
	char	c;

	c = str[i][16];
	j = 0;
	tetro->mass[i] = 1;
	tetro->fld[i] = 0;
	while (j < tetro->d * tetro->d)
	{
		if (str[0][j] == c)
			str[0][j] = 0;
		j++;
	}
	return (str[0]);
}

char	*ft_back(char **str, t_tetro *tetro)
{
	int i;
	int j;

	j = 1;
	i = ft_flag(tetro->ovl, tetro->d);
	while (j <= tetro->n)
	{
		if (tetro->fld[j] >= i)
		{
			str[0] = ft_restore(str, tetro, j);
		}
		j++;
	}
	tetro->rtr = rtrrestore(tetro->rtr, i + 1, tetro->d, tetro->n);
	while (i < tetro->d * tetro->d)
	{
		i++;
		if (i < tetro->d * tetro->d)
			tetro->ovl[i] = 0;
	}
	return (str[0]);
}
