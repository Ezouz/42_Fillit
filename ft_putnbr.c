/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:31:58 by ehouzard          #+#    #+#             */
/*   Updated: 2017/12/04 17:50:57 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putnbr(int n)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}
