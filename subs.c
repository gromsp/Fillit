/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:45:01 by adoyle            #+#    #+#             */
/*   Updated: 2019/03/01 16:45:45 by adoyle           ###   ########.fr       */
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
	// tetro->ovl[crd]++;
	tetro->rtr[crd][second] = 1;
}

char	*ft_write1(char **str, t_tetro *tetro, int s, int crd)
{
	str[0] = ft_paste(str[0], str[s], crd, tetro->d);
	tetro->mass[s] = 0;
	tetro->fld[s] = crd;
	return (str[0]);
}

// char	*ft_write(char **str, t_tetro *tetro)
// {
// 	str[0] = ft_paste(str[0], str[tetro->ccrd[1]], tetro->ccrd[0], tetro->d);
// 	tetro->mass[tetro->ccrd[1]] = 0;
// 	tetro->fld[tetro->ccrd[1]] = tetro->ccrd[0];
// 	return (str[0]);
// }

char	*ft_stupsubs(char **str, t_tetro *tetro, int f)
{
	int s;
	int crd;
	char 	*tmp;

	s = 1;
	tmp = ft_ftstrnew(tetro->d * tetro->d - 1);
	tmp = ft_ftstrcpy(tmp, str[0], tetro->d * tetro->d - 1);
	tetro->ccrd[0] = -1;
	while (s <= tetro->n)
	{
		crd = -1;
		if (tetro->mass[s] != 0)
			crd = ft_coordinate(tmp, str[s], tetro->d);
		if (crd >= 0)
		{
			tmp = ft_paste(tmp, str[s], crd, tetro->d);
			tetro->mass[s] = 0;
			tetro->flag = 1;
			// ft_qprintdbg(tmp, tetro->d);
		}
		// else if (ft_cmass(tetro->mass, tetro->n) > 0 && s >= tetro->n)
		// {
		// 	// printf("11111111111111111\n");
		// 	// ft_qprintdbg(tmp, tetro->d);
		// 	return (str[0]);
		// }		
		s++;
	}
	return (tmp);
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
		// if (crd >= 0 && (crd < tetro->ccrd[0] || tetro->ccrd[0] < 0))
		// 	ft_writecrd(tetro, crd, s);
		// else if (crd == tetro->ccrd[0] && crd >= 0 && tetro->rtr[crd][s] != 1)
		// 	ft_writerpt(tetro, crd, s);
		s++;
	}
	if (crd >= 0)
	{
		str[0] = ft_write1(str, tetro, s, crd);
		tetro->flag = 1;
	}
	return (str[0]);
}

// char	*ft_subs(char **str, t_tetro *tetro)
// {
// 	int s;
// 	int crd;
// 	int flag;

// 	s = 1;
// 	tetro->ccrd[0] = -1;
// 	while (s <= tetro->n)
// 	{
// 		crd = -1;
// 		if (tetro->mass[s] != 0)
// 			crd = ft_coordinate(str[0], str[s], tetro->d);
// 		// if (crd >= 0 && (crd < tetro->ccrd[0] || tetro->ccrd[0] < 0))
// 		// 	ft_writecrd(tetro, crd, s);
// 		// else if (crd == tetro->ccrd[0] && crd >= 0 && tetro->rtr[crd][s] != 1)
// 		// 	ft_writerpt(tetro, crd, s);
// 		s++;
// 	}
// 	if (tetro->ccrd[0] >= 0)
// 	{
// 		str[0] = ft_write(str, tetro);
// 		tetro->flag = 1;
// 	}
// 	return (str[0]);
// }
