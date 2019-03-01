/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:47:58 by adoyle            #+#    #+#             */
/*   Updated: 2019/03/01 13:47:58 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_bzeroint(int *s, size_t n)
{
	while (n-- > 0)
	{
		((int*)s)[n] = (int)0;
	}
}

void	ft_freetet(t_tetro *tetro)
{
	int count;
	int c;

	count = tetro->d;
	free(tetro->mass);
	free(tetro->ovl);
	free(tetro->fld);
	c = 0;
	while (c < count * count)
	{
		free(tetro->rtr[c]);
		c++;
	}
	free(tetro->rtr);
	free(tetro);
}

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
	str = ft_strnew(c * c);
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

char	*ft_init(char **str, int count, int diag)
{
	t_tetro	*tetro;
	int c;

	tetro = malloc(sizeof(t_tetro));
	tetro->d = diag;
	tetro->n = count;
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
	str[0] = ft_brute2(str, tetro);
	ft_freetet(tetro);
	return (str[0]);
}