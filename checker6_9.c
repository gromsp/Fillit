/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker6_9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:36:55 by qhetting          #+#    #+#             */
/*   Updated: 2019/03/14 15:09:07 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

int			check_6(char *tetr, int pos)
{
	int		sharps;

	sharps = 0;
	if (tetr[pos + DOWN] == '#')
		sharps++;
	if (tetr[pos - 1] == '#')
		sharps++;
	return (sharps);
}

int			check_7(char *tetr, int pos)
{
	int		sharps;

	sharps = 0;
	if (tetr[pos + UP] == '#')
		sharps++;
	if (tetr[pos + 1] == '#')
		sharps++;
	if (tetr[pos - 1] == '#')
		sharps++;
	return (sharps);
}

int			check_8(char *tetr, int pos)
{
	int sharps;

	sharps = 0;
	if (tetr[pos + UP] == '#')
		sharps++;
	if (tetr[pos + 1] == '#')
		sharps++;
	return (sharps);
}

int			check_9(char *tetr, int pos)
{
	int sharps;

	sharps = 0;
	if (tetr[pos + UP] == '#')
		sharps++;
	if (tetr[pos - 1] == '#')
		sharps++;
	return (sharps);
}

void		magick_stck(char **s, char **s_ptr, size_t *size)
{
	(*s_ptr) = *s;
	(*size) = 0;
}
