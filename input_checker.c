/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:11:52 by jbella            #+#    #+#             */
/*   Updated: 2018/04/11 11:16:45 by mbengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_neighboors(t_point c, int count, int pos, t_lst **items)
{
	t_lst		*tmp;
	int			i;

	i = 0;
	tmp = ft_lst_at(items, count);
	if (c.x > 0)
		if (ft_check(c.x - 1, c.y, pos, tmp) == 1)
			i++;
	if (c.x < 3)
		if (ft_check(c.x + 1, c.y, pos, tmp) == 1)
			i++;
	if (c.y > 0)
		if (ft_check(c.x, c.y - 1, pos, tmp) == 1)
			i++;
	if (c.y < 3)
		if (ft_check(c.x, c.y + 1, pos, tmp) == 1)
			i++;
	return (i);
}

int				sticked_together(t_lst **items)
{
	t_lst		*tmp;
	int			k;
	int			count;
	int			neighboors;

	count = 0;
	tmp = *items;
	while (tmp)
	{
		k = 0;
		neighboors = 0;
		while (k < 4)
		{
			if (check_neighboors(tmp->coord[k], count, k, items) == 0)
				return (0);
			neighboors += check_neighboors(tmp->coord[k], count, k, items);
			k++;
		}
		if (neighboors < 5)
			return (0);
		count++;
		tmp = tmp->next;
	}
	return (!(count > 26 || count == 0));
}

int				valid_char(char *buf, int *count, int k, t_lst **items)
{
	if (buf[k] == '.' || buf[k] == '#')
	{
		if (buf[k] == '#')
		{
			if (save_places(*count, items, k) == 1)
				return (1);
		}
	}
	else
		return (1);
	return (0);
}

int				core_check(char *buf, int ret, int *count, t_lst **items)
{
	int			k;

	k = 0;
	while (k < ret)
	{
		if (k > 3 && (k - 4) % 5 == 0)
		{
			if (buf[k] != '\n')
				return (1);
		}
		else
		{
			if (valid_char(buf, count, k, items) == 1)
				return (1);
		}
		k++;
	}
	(*count)++;
	return (0);
}

int				valid_input(const int fd, t_lst **items)
{
	int			ret;
	int			count;
	char		*buf;
	int			flag;

	count = 0;
	if (!(buf = malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		flag = 0;
		if (core_check(buf, ret, &count, items) == 1 || ret != 20)
			return (1);
		if ((ret = read(fd, buf, 1)) > 0)
		{
			if ((flag = 1) == 1 && buf[0] != '\n')
				return (-1);
		}
		if (count > 26)
			return (1);
	}
	if (flag == 1 || sticked_together(items) == 0)
		return (1);
	set_upmost_left_pos(items);
	return (0);
}
