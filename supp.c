/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:46:17 by adoyle            #+#    #+#             */
/*   Updated: 2019/03/01 18:06:01 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		high_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

int		ft_flag(int *ovl, int d)
{
	int i;

	i = d * d;
	while (i--)
	{
		if (ovl[i] != 0)
			return (i);
	}
	return (0);
}

int		ft_cmass(int *mass, int n)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (i <= n)
	{
		if (mass[i] == 1)
			count++;
		i++;
	}
	return (count);
}

int		ft_checkrtr(t_tetro *tetro)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= tetro->d * tetro->d)
	{
		while (j <= tetro->n)
		{
			if (tetro->rtr[i][j] == 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
