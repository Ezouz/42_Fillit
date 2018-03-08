/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordfig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:10:42 by ehouzard          #+#    #+#             */
/*   Updated: 2017/12/15 13:47:09 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fill_coord(t_list *lst, char *buf)
{
	int i;
	int k;
	int contact;

	i = 0;
	k = 0;
	contact = 0;
	while (k < BUF_SIZE)
	{
		if (buf[k] == '#')
		{
			ft_check_contact(buf, &k, &contact);
			ft_fill_fig(lst->fig, &i, k);
		}
		k++;
	}
	ft_coord_fig(lst->fig);
	ft_meas(lst);
	if (contact < 6)
		return (1);
	return (0);
}

void	ft_fill_fig(int *fig, int *i, int k)
{
	fig[(*i)] = ((k) / 5);
	(*i)++;
	fig[(*i)] = ((k) % 5);
	(*i)++;
}

void	ft_coord_fig(int *fig)
{
	int i;
	int x;
	int y;

	i = 0;
	x = fig[0];
	y = fig[1];
	while (i < 8)
	{
		if ((i % 2) == 0)
			fig[i] = fig[i] - x;
		if ((i % 2) != 0)
			fig[i] = fig[i] - y;
		i++;
	}
}

void	ft_meas(t_list *lst)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = -1;
	while (i < 8)
	{
		if (lst->fig[i] > x && (i % 2) == 0)
			x = lst->fig[i];
		if (lst->fig[i] > y && (i % 2) != 0)
			y = lst->fig[i];
		i++;
	}
	lst->height = x;
	lst->width = y;
}
