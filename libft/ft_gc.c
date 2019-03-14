/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:10:50 by qhetting          #+#    #+#             */
/*   Updated: 2019/03/14 14:13:44 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_malloced			*init(void *ptr)
{
	t_malloced		*head;

	head = malloc(sizeof(t_malloced));
	ft_bzero(head, sizeof(t_malloced));
	head->pointer = ptr;
	return (head);
}

void				append(void *ptr)
{
	t_malloced		*last;

	last = g_malloced;
	while (last->next)
		last = last->next;
	last->next = init(ptr);
}

void				ft_free(void **ptr)
{
	t_malloced		*temp;

	temp = g_malloced;
	if (!g_malloced)
	{
		free(*ptr);
		return ;
	}
	while (temp)
	{
		if ((size_t)temp->pointer == (size_t)(*ptr))
		{
			temp->is_freed = 1;
			break ;
		}
		temp = temp->next;
	}
	free(*ptr);
	*ptr = NULL;
}

void				ft_gc(void)
{
	t_malloced		*temp;

	if (!g_malloced)
		return ;
	while (g_malloced)
	{
		if (!g_malloced->is_freed)
			free(g_malloced->pointer);
		temp = g_malloced->next;
		free(g_malloced);
		g_malloced = temp;
		if (!g_malloced)
			break ;
	}
}
