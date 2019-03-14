/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:55:09 by qhetting          #+#    #+#             */
/*   Updated: 2019/03/14 17:00:55 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

int					pre_parse_pt1(char **str)
{
	size_t			lines;

	lines = (size_t)ft_count_symbol(*str, '\n');
	if ((lines + 1) % 5 != 0)
	{
		free(*str);
		return (0);
	}
	if (!is_req_symbols(str))
		return (0);
	remove_symbols(str, '\n');
	if (ft_strlen(*str) % 16 != 0)
	{
		free(*str);
		return (0);
	}
	return (1);
}

int					pre_parse(int fd, char **tetraminos)
{
	char			*str;
	size_t			lines;
	char			ptr[17];
	size_t			i;

	if (!(str = read_file(fd)))
		return (0);
	ptr[16] = 0;
	if (!pre_parse_pt1(&str))
		return (0);
	i = (size_t)str;
	lines = (size_t)-16;
	while ((lines += 16) < ft_strlen((char *)i))
	{
		ft_strncpy(ptr, str, 16);
		if (ft_count_symbol(ptr, '#') != 4 || ft_count_symbol(ptr, '.') != 12)
		{
			free(*tetraminos);
			throw_error();
		}
		str += 16;
	}
	*tetraminos = (char *)i;
	return (1);
}

int					get_flag(int pos, char *tetra)
{
	int				flag;

	if (y_(pos) > 0 && y_(pos) < 3)
		flag = getf_1(pos, tetra);
	else if (y_(pos) == 0)
	{
		if (x_(pos) > 0 && x_(pos) < 3)
			flag = check_4(tetra, pos);
		else if (x_(pos) == 0)
			flag = check_5(tetra, pos);
		else
			flag = check_6(tetra, pos);
	}
	else
	{
		if (x_(pos) > 0 && x_(pos) < 3)
			flag = check_7(tetra, pos);
		else if (x_(pos) == 0)
			flag = check_8(tetra, pos);
		else
			flag = check_9(tetra, pos);
	}
	return (flag);
}

int					validate_tetra(char **tetramino)
{
	int				pos;
	int				sharp_count;
	char			*tetra;
	int				flag;

	flag = 0;
	tetra = *tetramino;
	pos = 0;
	sharp_count = pos;
	while (pos < 16)
	{
		if (tetra[pos] == '#' && sharp_count < 4)
			flag += get_flag(pos, tetra);
		pos++;
	}
	return ((flag >= 6 && flag <= 8) ? 1 : 0);
}

int					validate(char **tetra)
{
	unsigned int	i;
	char			*cut;

	i = 0;
	cut = ft_memalloc(17);
	cut[16] = 0;
	while (i != ft_strlen(*tetra))
	{
		ft_memcpy(cut, (i + *(tetra)), 16);
		if (!validate_tetra(&cut))
			return (0);
		i += 16;
	}
	free(cut);
	return (1);
}
