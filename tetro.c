/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:47:02 by adoyle            #+#    #+#             */
/*   Updated: 2019/03/13 17:27:55 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_tetroinit(t_tetro *tetro)
{
	int c;
	int diag;
	int count;

	diag = tetro->d + 1;
	tetro->d = tetro->d + 1;
	count = tetro->n;
	tetro->mass = (int *)malloc((sizeof(int)) * (count + 1));
	tetro->ovl = (int *)malloc((sizeof(int)) * diag * diag);
	tetro->fld = (int *)malloc((sizeof(int)) * (count + 1));
	tetro->rtr = (int **)malloc(sizeof(int *) * (diag * diag));
	c = 0;
	while (c < diag * diag)
	{
		tetro->rtr[c] = malloc(sizeof(int) * (count + 1));
		ft_bzeroint(tetro->rtr[c++], count + 1);
	}
	ft_bzeroint(tetro->ovl, diag * diag);
	ft_bzeroint(tetro->fld, count + 1);
	c = 0;
	while (c <= count + 1)
		tetro->mass[c++] = 1;
}

char	*ft_freetetro(char *str, t_tetro *tetro)
{
	int c;
	int count;

	count = tetro->d;
	c = tetro->d + 1;
	free(str);
	str = ft_ftstrnew(c * c);
	free(tetro->mass);
	free(tetro->ovl);
	free(tetro->fld);
	c = 0;
	while (c < count * count)
		free(tetro->rtr[c++]);
	free(tetro->rtr);
	ft_tetroinit(tetro);
	return (str);
}

void	setmassone(t_tetro *tetro)
{
	int c;

	c = 0;
	while (c <= tetro->n + 1)
	{
		tetro->mass[c] = 1;
		c++;
	}
}

void	intend(char **str, t_tetro *tetro)
{
	tetro->flag = 0;
	str[0] = ft_ftstrnew(tetro->d * tetro->d - 1);
	recurse(str, tetro, 1, 0);
	if (tetro->flag == 0)
	{
		free(str[0]);
		str[0] = ft_init(str, tetro->n, tetro->d + 1);
	}
	ft_freetet(tetro);
}

char	*ft_init(char **str, int count, int diag)
{
	t_tetro	*tetro;
	int		c;

	tetro = malloc(sizeof(t_tetro));
	tetro->d = diag;
	tetro->n = count;
	tetro->mass = (int *)malloc((sizeof(int)) * (count + 2));
	tetro->ovl = (int *)malloc((sizeof(int)) * diag * diag);
	tetro->fld = (int *)malloc((sizeof(int)) * (count + 1));
	tetro->rtr = (int **)malloc(sizeof(int *) * (diag * diag));
	c = 0;
	while (c < diag * diag)
	{
		tetro->rtr[c] = malloc(sizeof(int) * (count + 1));
		ft_bzeroint(tetro->rtr[c++], count + 1);
	}
	ft_bzeroint(tetro->ovl, diag * diag);
	ft_bzeroint(tetro->fld, count + 1);
	c = 0;
	setmassone(tetro);
	intend(str, tetro);
	return (str[0]);
}
