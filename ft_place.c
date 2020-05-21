/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:41:23 by jbella            #+#    #+#             */
/*   Updated: 2018/04/11 11:12:16 by mbengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_is_posable(t_point c[4], int pos, t_grid_data *g)
{
	int			k;
	int			check;
	int			size;

	size = g->size;
	k = 0;
	check = 0;
	while (k < 4)
	{
		if (pos + c[k].y * size + c[k].x < size * size && pos % size + c[k].x
				< size && g->grid[pos + c[k].y * size + c[k].x] == '.')
		{
			check++;
		}
		k++;
	}
	if (check == 4)
		return (1);
	return (0);
}

int				init_grid(t_grid_data **g, t_lst **items, int size)
{
	t_lst		*tmp;
	int			k;

	tmp = *items;
	while (tmp)
	{
		tmp->pos = 0;
		tmp = tmp->next;
	}
	k = 0;
	if (!(*g = malloc(sizeof(t_grid_data))))
		return (-1);
	if (!((*g)->grid = malloc(sizeof(char) * size * size)))
		return (-1);
	while (k < size * size)
	{
		(*g)->grid[k] = '.';
		k++;
	}
	(*g)->size = size;
	return (0);
}

void			ft_pose(int count, t_grid_data **g, int pos, t_lst *tmp)
{
	char		letter;
	int			k;

	k = 0;
	letter = 'A' + count;
	while (k < 4)
	{
		(*g)->grid[pos + tmp->coord[k].x + tmp->coord[k].y * (*g)->size] =
			letter;
		k++;
	}
}

int				ft_not_posable(int *count, t_lst **tmp, t_lst **items,
		t_grid_data **g)
{
	if (*tmp && (*tmp)->pos == (*g)->size * (*g)->size)
	{
		if (*count != 0)
		{
			(*count)--;
			(*tmp)->pos = 0;
			*tmp = ft_lst_at(items, *count);
			ft_clean(*tmp, g);
			(*tmp)->pos++;
		}
		else
			return (0);
	}
	return (1);
}

int				ft_place(t_lst **items, t_grid_data **g)
{
	t_lst		*tmp;
	int			count;

	count = 0;
	tmp = *items;
	while (tmp)
	{
		while (tmp && tmp->pos < (*g)->size * (*g)->size)
		{
			if (ft_is_posable(tmp->coord, tmp->pos, *g) == 1)
			{
				ft_pose(count, g, tmp->pos, tmp);
				tmp = tmp->next;
				count++;
				break ;
			}
			else
				tmp->pos++;
		}
		if (ft_not_posable(&count, &tmp, items, g) == 0)
			return (0);
	}
	if (count == (ft_list_size(items)))
		return (1);
	return (0);
}
