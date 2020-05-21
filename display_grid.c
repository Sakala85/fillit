/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:39:44 by jbella            #+#    #+#             */
/*   Updated: 2018/04/04 17:32:29 by jbella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_show_grid(t_grid_data *g)
{
	int		k;
	int		i;

	k = 0;
	while (k < g->size)
	{
		i = 0;
		while (i < g->size)
		{
			ft_putchar(g->grid[k * g->size + i]);
			i++;
		}
		ft_putchar('\n');
		k++;
	}
}
