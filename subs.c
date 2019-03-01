/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:47:48 by adoyle            #+#    #+#             */
/*   Updated: 2019/03/01 13:47:48 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_writecrd(t_tetro *tetro, int crd, int second)
{
	tetro->ccrd[0] = crd;
	tetro->ccrd[1] = second;
}

void	ft_writerpt(t_tetro *tetro, int crd, int second)
{
	tetro->ovl[crd]++;
	tetro->rtr[crd][second] = 1;
}

char	*ft_write(char **str, t_tetro *tetro)
{
	str[0] = ft_paste(str[0], str[tetro->ccrd[1]], tetro->ccrd[0], tetro->d);
	tetro->mass[tetro->ccrd[1]] = 0;
	tetro->fld[tetro->ccrd[1]] = tetro->ccrd[0];
	return (str[0]);
}

char	*ft_subs(char **str, t_tetro *tetro)
{
	int s;
	int crd;
	int flag;

	s = 1;
	tetro->ccrd[0] = -1;
	while (s <= tetro->n)
	{
		crd = -1;
		if (tetro->mass[s] != 0)
			crd = ft_coordinate(str[0], str[s], tetro->d);
		// printf("crd - %d || s - %d\n", crd, s);
		if (crd >= 0 && (crd < tetro->ccrd[0] || tetro->ccrd[0] < 0))
			ft_writecrd(tetro, crd, s);
		else if (crd == tetro->ccrd[0] && crd >= 0 && tetro->rtr[crd][s] != 1)
			ft_writerpt(tetro, crd, s);
		s++;
	}
	if (tetro->ccrd[0] >= 0)
		str[0] = ft_write(str, tetro);
	return (str[0]);
}