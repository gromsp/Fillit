/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker0_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:34:44 by qhetting          #+#    #+#             */
/*   Updated: 2019/03/14 12:36:43 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

int				check_1(char *tetr, int pos)
{
	int			sharps;

	sharps = 0;
	if (tetr[pos + UP] == '#')
		sharps++;
	if (tetr[pos + 1] == '#')
		sharps++;
	if (tetr[pos + DOWN] == '#')
		sharps++;
	if (tetr[pos - 1] == '#')
		sharps++;
	return (sharps);
}

int				check_2(char *tetr, int pos)
{
	int			sharps;

	sharps = 0;
	if (tetr[pos + UP] == '#')
		sharps++;
	if (tetr[pos + 1] == '#')
		sharps++;
	if (tetr[pos + DOWN] == '#')
		sharps++;
	return (sharps);
}

int				check_3(char *tetr, int pos)
{
	int sharps;

	sharps = 0;
	if (tetr[pos + UP] == '#')
		sharps++;
	if (tetr[pos + DOWN] == '#')
		sharps++;
	if (tetr[pos - 1] == '#')
		sharps++;
	return (sharps);
}

int				check_4(char *tetr, int pos)
{
	int			sharps;

	sharps = 0;
	if (tetr[pos + 1] == '#')
		sharps++;
	if (tetr[pos + DOWN] == '#')
		sharps++;
	if (tetr[pos - 1] == '#')
		sharps++;
	return (sharps);
}

int				check_5(char *tetr, int pos)
{
	int			sharps;

	sharps = 0;
	if (tetr[pos + 1] == '#')
		sharps++;
	if (tetr[pos + DOWN] == '#')
		sharps++;
	return (sharps);
}
