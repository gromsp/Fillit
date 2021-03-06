/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:18:18 by adoyle            #+#    #+#             */
/*   Updated: 2019/03/29 20:47:40 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

char	*ft_ftstrcpy(char *dest, char *str, int n)
{
	int i;

	i = 0;
	if (str == NULL)
		return (str);
	while (i <= n)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}

char	*ft_movenewstr(char *str1, int d)
{
	char	*str;

	str = ft_ftstrnew(d * d - 1);
	str = ft_ftstrcpy(str, str1, d * d - 1);
	return (str);
}

int		ft_move(char *str1, char *str2, int crd, int d)
{
	char	*str;
	int		j;
	int		g;

	j = 0;
	str = ft_movenewstr(str1, d);
	while (j < 16)
	{
		g = (crd + (j % 4)) + d * (j / 4);
		if (((crd + (j % 4)) + d * (j / 4) > d * d - 1 && str2[j] == 1) ||
			((g / d) - (crd / d) != (j / 4) && str2[j] == 1))
			str[0] = 2;
		if (str2[j] == 1 && g < d * d - 1 && str1[0] != 2)
			str[g] = str1[(crd + j % 4) + d * (j / 4)] + str2[j];
		if (str[0] == 2 || crd < 0 || (str2[j] == 1 && str[g] >= 2))
		{
			free(str);
			return (1);
		}
		j++;
	}
	free(str);
	return (0);
}

int		ft_checkd3(char *s, char *a)
{
	if (s[3] == 1 || s[12] == 1)
		return (1);
	if (a[3] == 1 || a[12] == 1)
		return (1);
	return (0);
}

int		ft_coordinate(char *str1, char *str2, int d)
{
	int		i;
	char	*tmp;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (-5);
	tmp = ft_movenewstr(str1, 4);
	if (d == 3 && ft_checkd3(str1, str2) == 1)
		return (-5);
	tmp = ft_d3(tmp);
	while (i != d * d)
	{
		if (tmp[i] == 0)
		{
			if (ft_move(tmp, str2, i - ft_fsmb(str2), d) == 0)
			{
				free(tmp);
				return (i);
			}
		}
		i++;
	}
	free(tmp);
	return (-5);
}
