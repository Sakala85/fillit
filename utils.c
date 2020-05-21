/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 09:41:59 by jbella            #+#    #+#             */
/*   Updated: 2018/04/05 09:52:14 by jbella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			is_squared_number(int nb)
{
	int		k;

	k = 2;
	if (k <= 0)
		return (0);
	if (k == 1)
		return (k);
	while (k < nb)
	{
		if (k * k == nb)
			return (k);
		k++;
	}
	return (0);
}

int			next_square(int a)
{
	while (!is_squared_number(a))
		a++;
	return (a);
}
