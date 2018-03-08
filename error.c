/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:25:36 by ehouzard          #+#    #+#             */
/*   Updated: 2017/12/15 16:22:35 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(int ac)
{
	if (ac != 2)
	{
		write(1, "usage: ./fillit target_file\n", 28);
		return (1);
	}
	return (0);
}

int		ft_error2(void)
{
	write(1, "error\n", 6);
	return (1);
}
