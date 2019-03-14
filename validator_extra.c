/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:28:45 by qhetting          #+#    #+#             */
/*   Updated: 2019/03/14 15:44:31 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

char				*get_string(char **tet_inpt, char **tetraminos,
								unsigned char i, char **current)
{
	ft_memcpy((*current), *tet_inpt, 16);
	tetraminos[i] = crop(current);
	tetraminos[i][16] = (char)('A' - 1 + i);
	*tet_inpt += 16;
	return (*current);
}

int					getf_1(int pos, char *tetra)
{
	int				flag;

	if (x_(pos) > 0 && x_(pos) < 3)
		flag = check_1(tetra, pos);
	else if (x_(pos) == 0)
		flag = check_2(tetra, pos);
	else
		flag = check_3(tetra, pos);
	return (flag);
}
