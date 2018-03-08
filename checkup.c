/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:14:50 by ehouzard          #+#    #+#             */
/*   Updated: 2017/12/15 15:54:41 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_lastn(char *buf, int re)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (i < re)
	{
		if (buf[i] == '\n')
			n++;
		i++;
	}
	if (n == 5)
		return (1);
	return (0);
}

int		ft_check_char(char *buf, int *i, int *dot, int *hash)
{
	if ((((*i) + 1) % 5) > 0 && (buf[(*i)] == '.' || buf[(*i)] == '#'))
	{
		if (buf[(*i)] == '.')
			(*dot)++;
		if (buf[(*i)] == '#')
			(*hash)++;
	}
	if (((*i) + 1) % 5 == 0 && buf[(*i)] != '\n')
		return (1);
	return (0);
}

int		ft_check_arg(char *buf, int re)
{
	int i;
	int hash;
	int dot;

	i = 0;
	hash = 0;
	dot = 0;
	while (i < re)
	{
		if (ft_check_char(buf, &i, &dot, &hash) == 1)
			return (1);
		i++;
	}
	if (re < 20)
		return (1);
	if (dot == 12 && hash == 4)
		return (0);
	return (1);
}

void	ft_check_contact(char *buf, int *k, int *contact)
{
	if (buf[(*k) + 1] == '#' && (*k) <= 18)
		(*contact)++;
	if (buf[(*k) - 1] == '#' && (*k) >= 1)
		(*contact)++;
	if (buf[(*k) + 5] == '#' && (*k) <= 15)
		(*contact)++;
	if (buf[(*k) - 5] == '#' && (*k) >= 5)
		(*contact)++;
}
