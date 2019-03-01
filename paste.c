/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:41:34 by adoyle            #+#    #+#             */
/*   Updated: 2019/03/01 16:49:55 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

char	*ft_paste(char *str1, char *str2, int crd, int d)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	crd = crd - ft_fsmb(str2);
	i = crd / d;
	while (j < 16)
	{
		if (str2[j] == 1 && (crd + (j % 4)) + d * (j / 4) < d * d)
			str1[(crd + (j % 4)) + d * (j / 4)] = str2[16];
		j++;
	}
	return (str1);
}

char	*ft_paste3(char *str1, char *str2, int crd, int d)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_ftstrnew(d * d);
	str = ft_ftstrcpy(str, str1, d * d);
	while (j < 16)
	{
		if (str[j] == 1)
			str[j] = str1[9];
		j++;
	}
	i = crd / d;
	j = 0;
	while (j < 16)
		str[(crd + (j % 4)) + d * (j / 4)] = str2[16];
	return (str);
}
