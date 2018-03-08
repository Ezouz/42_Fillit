/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:01:51 by ehouzard          #+#    #+#             */
/*   Updated: 2017/12/20 13:59:08 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_adl	begin;
	t_list	*neo;
	char	**tab;

	tab = NULL;
	neo = ft_lst_tetriminos();
	begin.alst = neo;
	ft_error(argc);
	if (ft_openclose_file(argv[1], neo) == 1)
	{
		ft_list_clear(&begin.alst);
		return (1);
	}
	tab = ft_sendable(neo);
	ft_print_words_tables(tab);
	ft_free_tab(tab);
	ft_list_clear(&begin.alst);
	return (0);
}

void	ft_print_words_tables(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
