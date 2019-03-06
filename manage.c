/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:40:36 by adoyle            #+#    #+#             */
/*   Updated: 2019/03/01 17:28:56 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

char	*ft_fpaste(char **str, t_tetro *tetro)
{
	int i;
	int j;

	j = 1;
	i = ft_flag(tetro->ovl, tetro->d);
	while (j <= tetro->n)
	{
		if (tetro->rtr[i][j] == 1)
		{
			str[0] = ft_paste(str[0], str[j], i, tetro->d);
			tetro->mass[j] = 0;
			tetro->fld[j] = i;
			tetro->rtr[i][j] = 0;
			if (tetro->ovl[i] > 0)
				tetro->ovl[i]--;
			return (str[0]);
		}
		j++;
	}
	return (str[0]);
}

char	*ft_bback(char **str, t_tetro *tetro)
{
	str[0] = ft_back(str, tetro);
	str[0] = ft_fpaste(str, tetro);
	return (str[0]);
}

char	*ft_brute2(char **str, t_tetro *tetro)
{
	int first;
	int crd;

	first = 0;
	str[0] = ft_ftstrnew(tetro->d * tetro->d - 1);
	while (first++ <= tetro->n)
	{
		tetro->flag == 0;
		str[0] = ft_stupsubs(str, tetro);
		if (tetro->flag == 1)
			return (ft_quadforprin(str[0], tetro->d));
		str[0] = ft_subs(str, tetro);
		if (first == tetro->n)
		{
			if (ft_cmass(tetro->mass, tetro->n) > 0 && ft_checkrtr(tetro) < 0)
				str[0] = ft_bback(str, tetro);
			else if (ft_cmass(tetro->mass, tetro->n) <= 0)
				return (ft_quadforprin(str[0], tetro->d));
			if (ft_checkrtr(tetro) == 0)
				str[0] = ft_freetetro(str[0], tetro);
			first = 0;
		}
	}
	return (str[0]);
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
