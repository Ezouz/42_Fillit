/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstthings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:58:29 by ehouzard          #+#    #+#             */
/*   Updated: 2017/12/20 13:52:24 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*ft_lst_tetriminos(void)
{
	t_list	*neo;

	if (!(neo = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (!(neo->fig = ft_memalloc(8)))
	{
		free(neo);
		return (NULL);
	}
	neo->tetriminos = 'A';
	neo->width = 0;
	neo->height = 0;
	neo->next = NULL;
	return (neo);
}

void		ft_list_clear(t_list **begin_list)
{
	t_list *tmp;

	tmp = NULL;
	while (*begin_list)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp->fig);
		free(tmp);
	}
}

int			ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}
