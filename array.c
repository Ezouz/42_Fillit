/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:07:46 by ehouzard          #+#    #+#             */
/*   Updated: 2017/12/20 14:00:05 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrtfortabsize(int nb)
{
	int x;

	x = 1;
	while ((x * x) <= nb)
	{
		if ((x * x) == nb)
			return (x);
		x++;
	}
	if ((x * x) > nb)
		return (x);
	return (0);
}

char		**ft_initialize_tab(int size)
{
	char	**tab;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(tab = ft_memalloc((sizeof(char*) * size) + 1)))
		return (NULL);
	while (x < size)
	{
		if (!(tab[x] = ft_strnew(size)))
			return (NULL);
		y = 0;
		while (y < size)
		{
			tab[x][y] = '.';
			y++;
		}
		x++;
	}
	return (tab);
}

void		ft_undocoordtotab(char **tab, t_list *elem, int size)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (tab[x][y] == elem->tetriminos)
				tab[x][y] = '.';
			y++;
		}
		x++;
	}
}

int			ft_coordtotab(t_list *elem, char **tab, int *i, int size)
{
	int d;
	int x;
	int y;

	d = 0;
	x = (*i) / size;
	y = (*i) % size;
	if (!ft_nosegfault_x(size, elem, (*i)))
		return (1);
	if (!ft_nosegfault_y(size, elem, i))
		return (1);
	while (d < 8)
	{
		if (tab[(x + elem->fig[d])][(y + elem->fig[d + 1])] == '.')
		{
			tab[(x + elem->fig[d])][(y + elem->fig[d + 1])] = elem->tetriminos;
			d = d + 2;
		}
		else
		{
			ft_undocoordtotab(tab, elem, size);
			return (1);
		}
	}
	return (0);
}

void		ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}
