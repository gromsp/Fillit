/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:58:51 by qhetting          #+#    #+#             */
/*   Updated: 2019/03/14 16:57:44 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

int			x_(int pos)
{
	return (pos % 4);
}

int			y_(int pos)
{
	return (pos / 4);
}

void		remove_symbols(char **s, char c)
{
	char	*s_ptr;
	size_t	size;
	char	*ret;

	magick_stck(s, &s_ptr, &size);
	while (*s_ptr)
	{
		if (*s_ptr != c)
			size++;
		s_ptr++;
	}
	ret = ft_strnew(size);
	s_ptr = *s;
	size = (size_t)ret;
	while (**s)
	{
		if (**s != c)
		{
			*ret = **s;
			ret++;
		}
		(*s)++;
	}
	free(s_ptr);
	*s = (char *)(size);
}

int			find_x_r_offset(char *tetra)
{
	int		x;
	int		y;

	x = 3;
	while (x != 0)
	{
		y = 4;
		while (y != 0)
		{
			if (tetra[x + (y * WIDTH)] == 1)
				return (x);
			y--;
		}
		x--;
	}
	return (0);
}

int			find_y_r_offset(char *tetra)
{
	int		x;
	int		y;

	y = 3;
	while (y >= 0)
	{
		x = 3;
		while (x >= 0)
		{
			if (tetra[x + (y * WIDTH) - 1] == 1)
				return (y);
			x--;
		}
		y--;
	}
	return (0);
}
