/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:07:34 by ehouzard          #+#    #+#             */
/*   Updated: 2017/12/05 15:45:33 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	cmp;

	cmp = 0;
	if (!(str = (char*)malloc((sizeof(char) * size) + 1)))
		return (NULL);
	while (cmp < size)
		str[cmp++] = '\0';
	str[cmp] = '\0';
	return (str);
}
