/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:47:39 by jbella            #+#    #+#             */
/*   Updated: 2018/04/04 15:42:17 by jbella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst		*ft_create_elem(void)
{
	t_lst		*el;

	if ((el = malloc(sizeof(*el))) == NULL)
		return (NULL);
	el->index = 0;
	el->next = NULL;
	el->pos = 0;
	return (el);
}

t_lst		*ft_lst_at(t_lst **items, int count)
{
	t_lst		*tmp;

	tmp = *items;
	while (count > 0)
	{
		tmp = tmp->next;
		count--;
	}
	return (tmp);
}

int			ft_list_size(t_lst **items)
{
	t_lst	*tmp;
	int		size;

	size = 0;
	tmp = *items;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
