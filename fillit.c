/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:12:02 by jbella            #+#    #+#             */
/*   Updated: 2018/04/11 11:31:34 by jbella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					succes_open(int fd, t_lst **items)
{
	t_grid_data		*g;

	if (valid_input(fd, items) == 0)
	{
		init_grid(&g, items, is_squared_number(
					next_square(ft_list_size(items))));
		while (ft_place(items, &g) == 0)
		{
			init_grid(&g, items, (g->size) + 1);
		}
		ft_show_grid(g);
	}
	else
	{
		ft_putendl("error");
		return (1);
	}
	return (0);
}

int					ft_check(int x, int y, int pos, t_lst *tmp)
{
	int				k;

	k = 0;
	while (k < 4)
	{
		if (k != pos)
		{
			if (tmp->coord[k].x == x && tmp->coord[k].y == y)
				return (1);
		}
		k++;
	}
	return (0);
}

void				ft_clean(t_lst *tmp, t_grid_data **g)
{
	int				pos;
	int				k;

	k = 0;
	pos = tmp->pos;
	while (k < 4)
	{
		(*g)->grid[pos + tmp->coord[k].x + tmp->coord[k].y * (*g)->size] = '.';
		k++;
	}
}

int					main(int argc, char **argv)
{
	int				fd;
	t_lst			*items;

	items = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putendl(" <input_file>");
		return (2);
	}
	if ((fd = open(argv[1], O_RDONLY)) != -1)
	{
		if (succes_open(fd, &items) == 1)
			return (1);
	}
	else
	{
		ft_putendl("error");
		return (1);
	}
	return (0);
}
