/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:43:14 by ehouzard          #+#    #+#             */
/*   Updated: 2017/12/19 14:57:08 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read_file(int fd, t_list *lst, char *buf, int re)
{
	int		count;
	int		n;

	count = 0;
	n = 0;
	while ((re = read(fd, buf, BUF_SIZE)))
	{
		if (ft_check_arg(buf, re) != 1)
		{
			if (ft_fill_coord(lst, buf) == 1)
				return (ft_error2());
			lst->tetriminos = count + 65;
			if (!(lst->next = ft_lst_tetriminos()))
				return (ft_error2());
			lst = lst->next;
			n = n + ft_check_lastn(buf, re);
			count++;
		}
		else
			return (ft_error2());
	}
	if (n == count)
		return (ft_error2());
	return (0);
}

int		ft_openclose_file(char *av, t_list *lst)
{
	char	buf[BUF_SIZE + 1];
	int		re;
	int		fd;
	int		quit;

	buf[BUF_SIZE] = 0;
	re = 0;
	quit = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	if ((ft_read_file(fd, lst, buf, re)) == 1)
		quit = 1;
	if (close(fd) == -1)
	{
		return (1);
	}
	return (quit);
}
