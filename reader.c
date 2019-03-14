/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:38:39 by qhetting          #+#    #+#             */
/*   Updated: 2019/03/14 16:56:56 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

char			*read_file(int fd)
{
	char		*res;
	int			ret;
	int			i;

	res = ft_strnew(4096);
	ret = (int)read(fd, res, 4096);
	if (ret <= 0)
	{
		free(res);
		res = 0x0;
		return (res);
	}
	i = 20;
	while (i < (int)ft_strlen(res))
	{
		if (res[i] != '\n' && ((i + 20) < (int)ft_strlen(res)))
			throw_error();
		i += 21;
	}
	close(fd);
	return (res);
}

int				is_req_symbols(char **ch)
{
	char		*ptr;

	ptr = *ch - 1;
	while (*(++ptr))
		if (!(*ptr == '.' || *ptr == '\n' || *ptr == '#'))
			return (0);
	return (1);
}

int				ft_count_symbol(char *str, char ch)
{
	int			i;

	i = 0;
	while (*str)
	{
		if (*str == ch)
			i++;
		str++;
	}
	return (i);
}
