/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:11:55 by ehouzard          #+#    #+#             */
/*   Updated: 2017/12/04 15:11:53 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memalloc(size_t size)
{
	size_t			cmp;
	void			*ptr;
	unsigned char	*ucptr;

	cmp = 0;
	if (!(ptr = (void*)malloc(sizeof(int) * size)))
		return (NULL);
	ucptr = ptr;
	while (cmp < size)
	{
		ucptr[cmp++] = 0;
	}
	return (ptr);
}
