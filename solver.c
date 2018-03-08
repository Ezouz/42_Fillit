/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:14:11 by ehouzard          #+#    #+#             */
/*   Updated: 2017/12/20 13:57:58 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**ft_sendable(t_list *begin)
{
	int			i;
	int			size_tab;
	char		**tab;
	t_list		*elem;

	i = 0;
	elem = begin;
	size_tab = ft_sqrtfortabsize(ft_list_size(elem) * 4);
	tab = ft_initialize_tab(size_tab);
	elem = begin;
	while (ft_tracking(elem, tab, i, size_tab))
	{
		ft_free_tab(tab);
		size_tab = size_tab + 1;
		tab = ft_initialize_tab(size_tab);
		elem = begin;
	}
	return (tab);
}

int				ft_tracking(t_list *elem, char **tab, int i, int size)
{
	if (!ft_list_size(elem))
		return (0);
	if (ft_checkpoint(tab, &i, size))
		return (1);
	if (!ft_nosegfault_x(size, elem, i) || !ft_nosegfault_y(size, elem, &i))
	{
		if (!ft_nosegfault_x(size, elem, i))
			return (1);
		if (elem->height + 1 > size || elem->width + 1 > size)
			return (1);
		if (i >= size * size)
			return (1);
	}
	if (!ft_coordtotab(elem, tab, &i, size))
	{
		if (!ft_tracking(elem->next, tab, 0, size))
			return (0);
		else
			ft_undocoordtotab(tab, elem, size);
	}
	return (ft_tracking(elem, tab, i + 1, size));
}

int				ft_checkpoint(char **tab, int *i, int size)
{
	int x;
	int y;
	int size_tab;

	size_tab = size * size;
	while ((*i) < size_tab)
	{
		x = (*i) / size;
		y = (*i) % size;
		if (tab[x][y] == '.')
			return (0);
		(*i)++;
	}
	return (1);
}

int				ft_nosegfault_x(int size, t_list *elem, int idx)
{
	if ((idx / size) + elem->height >= size && idx <= (size * size))
		return (0);
	return (1);
}

int				ft_nosegfault_y(int size, t_list *elem, int *idx)
{
	if (((*idx) % size) + elem->width >= size && (*idx) <= (size * size))
	{
		(*idx) = (*idx) + (size - ((*idx) % size));
		return (0);
	}
	return (1);
}
