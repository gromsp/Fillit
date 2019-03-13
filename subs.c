/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:45:01 by adoyle            #+#    #+#             */
/*   Updated: 2019/03/13 17:04:04 by adoyle           ###   ########.fr       */
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
	tetro->rtr[crd][second] = 1;
}

char	*ft_write1(char **str, t_tetro *tetro, int s, int crd)
{
	str[0] = ft_paste(str[0], str[s], crd, tetro->d);
	tetro->mass[s] = 0;
	tetro->fld[s] = crd;
	return (str[0]);
}

char	*ft_subs(char **str, t_tetro *tetro)
{
	int s;
	int crd;

	s = 1;
	tetro->ccrd[0] = -1;
	while (s <= tetro->n)
	{
		crd = -1;
		if (tetro->mass[s] != 0)
			crd = ft_coordinate(str[0], str[s], tetro->d);
		s++;
	}
	if (crd >= 0)
	{
		str[0] = ft_write1(str, tetro, s, crd);
		tetro->flag = 1;
	}
	return (str[0]);
}
