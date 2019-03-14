/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:36:01 by qhetting          #+#    #+#             */
/*   Updated: 2019/03/14 14:15:51 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_malloced *g_malloced = NULL;

void		*ft_memalloc(size_t size)
{
	void	*ch;

	ch = malloc(size);
	ft_bzero(ch, size);
	if (g_malloced == NULL)
		g_malloced = init(ch);
	else
		append(ch);
	return (ch);
}
