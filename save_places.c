/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_places.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:50:56 by jbella            #+#    #+#             */
/*   Updated: 2018/04/11 11:15:29 by mbengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		init_places(t_lst **items)
{
	if (*items == NULL)
	{
		if (!(*items = ft_create_elem()))
			return (-1);
		(*items)->index = 0;
	}
	return (0);
}

int		save_places(int count, t_lst **items, int k)
{
	t_lst		*tmp;

	if (init_places(items) == -1)
		return (-1);
	tmp = *items;
	while (count > 0)
	{
		if (tmp->next == NULL)
		{
			if (!(tmp->next = ft_create_elem()))
				return (-1);
			tmp->index = 0;
		}
		tmp = tmp->next;
		count--;
	}
	if (tmp->index < 4)
	{
		(tmp->coord[tmp->index]).x = k % 5;
		(tmp->coord[tmp->index]).y = k / 5;
	}
	else
		return (1);
	tmp->index += 1;
	return (0);
}

void	get_offset(t_lst *item, int *offset_x, int *offset_y)
{
	int		k;

	k = 0;
	*offset_x = 3;
	*offset_y = 3;
	while (k < 4)
	{
		if (item->coord[k].x < *offset_x)
			*offset_x = item->coord[k].x;
		if (item->coord[k].y < *offset_y)
			*offset_y = item->coord[k].y;
		k++;
	}
}

void	set_upmost_left_pos(t_lst **items)
{
	t_lst		*tmp;
	int			offset_x;
	int			offset_y;
	int			k;

	tmp = *items;
	while (tmp)
	{
		get_offset(tmp, &offset_x, &offset_y);
		k = 0;
		while (k < 4)
		{
			tmp->coord[k].x -= offset_x;
			tmp->coord[k].y -= offset_y;
			k++;
		}
		tmp = tmp->next;
	}
}
