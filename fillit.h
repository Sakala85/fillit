/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:12:56 by jbella            #+#    #+#             */
/*   Updated: 2018/04/11 11:17:12 by mbengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 20
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"

typedef struct		s_point
{
	int x;
	int y;
}					t_point;

typedef struct		s_lst
{
	t_point			coord[4];
	int				index;
	struct s_lst	*next;
	int				pos;
}					t_lst;

typedef struct		s_grid_data
{
	char			*grid;
	int				size;
}					t_grid_data;

int					valid_input(const int fd, t_lst **items);
int					sticked_together(t_lst **items);
t_lst				*ft_create_elem(void);
int					check_neighboors(t_point c,
		int count, int pos, t_lst **items);
int					ft_check(int x, int y, int pos, t_lst *tmp);
int					core_check(char *buf, int ret, int *count, t_lst **items);
t_lst				*ft_lst_at(t_lst **items, int count);
int					ft_list_size(t_lst **items);
int					succes_open(int fd, t_lst **items);
int					save_places(int count, t_lst **items, int k);
void				set_upmost_left_pos(t_lst **items);
void				get_offset(t_lst *item, int *offset_x, int *offset_y);
void				ft_show_grid(t_grid_data *g);
int					is_squared_number(int nb);
int					next_square(int a);
int					init_grid(t_grid_data **g, t_lst **item, int size);
int					ft_place(t_lst **items, t_grid_data **g);
void				ft_clean(t_lst *tmp, t_grid_data **g);
int					ft_check(int x, int y, int pos, t_lst *tmp);
void				show_content(t_lst *items);
void				show_item_content(t_lst *item);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *s);
#endif
