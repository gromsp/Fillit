/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:36:47 by adoyle            #+#    #+#             */
/*   Updated: 2019/03/13 15:42:10 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_ftbzero(void *s, size_t n)
{
	while (n-- > 0)
	{
		((char*)s)[n] = (char)0;
	}
}

void	*ft_ftmemalloc(size_t size)
{
	void	*dest;

	dest = NULL;
	if (size == 0)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * size);
	if (dest == NULL)
		return (NULL);
	ft_ftbzero(dest, size);
	return (dest);
}

char	*ft_ftstrnew(size_t size)
{
	char *str;

	str = (char *)ft_ftmemalloc(size + 1);
	return (str);
}
