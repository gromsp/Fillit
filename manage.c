/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:40:36 by adoyle            #+#    #+#             */
/*   Updated: 2019/03/13 17:56:38 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

char	*ft_frestore(char **str, t_tetro *tetro, int i)
{
	while (i <= tetro->n)
	{
		str[0] = ft_restore(str, tetro, i);
		i++;
	}
	return (str[0]);
}

void	recurse(char **str, t_tetro *tetro, int i, int crd)
{
	if (i > 0 && i <= tetro->n && crd < tetro->d * tetro->d)
	{
		while (crd < tetro->d * tetro->d && tetro->mass[i] == 1)
		{
			if (ft_move(str[0], str[i], crd - ft_fsmb(str[i]), tetro->d) == 0)
			{
				str[0] = ft_paste(str[0], str[i], crd, tetro->d);
				tetro->mass[i] = 0;
				tetro->fld[i] = crd;
				recurse(str, tetro, i + 1, 0);
			}
			crd++;
		}
		if (ft_cmass(tetro->mass, tetro->n) == 0 && tetro->flag != 1)
		{
			ft_quadforprin(str[0], tetro->d);
			tetro->flag = 1;
			return ;
		}
		if (crd >= tetro->d * tetro->d - 1 && tetro->flag != 1)
			str[0] = ft_frestore(str, tetro, i - 1);
	}
	return ;
}

void	flt(char **str, t_tetro *tetro)
{
	int i;

	i = 0;
	while (i == tetro->flag)
	{
		if (tetro->flag == 1)
			i = -7;
		else
			str[0] = ft_init(str, tetro->n, tetro->d + 1);
	}
}

char	*ft_brute(char **str, int n)
{
	int d;
	int ttr[3];

	d = high_sqrt(4 * n);
	ttr[1] = 0;
	str[0] = ft_ftstrnew(d * d - 1);
	while (ttr[1]++ < n && d == 3)
	{
		ttr[2] = 0;
		while (ttr[2]++ < n)
		{
			ttr[0] = -1;
			if (ttr[1] != ttr[2])
				ttr[0] = ft_coordinate(str[ttr[1]], str[ttr[2]], d);
			if (ttr[1] != ttr[2] && ttr[0] >= 0)
			{
				str[0] = ft_paste3(ft_d3(str[ttr[1]]), str[ttr[2]], ttr[0], d);
				ft_quadforprin(str[0], d);
				return (str[0]);
			}
		}
	}
	free(str[0]);
	str[0] = ft_init(str, n, d);
	return (str[0]);
}

void	ft_fillit(char **str, int n)
{
	str[0] = ft_brute(str, n);
}
