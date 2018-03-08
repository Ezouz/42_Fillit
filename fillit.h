/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:01:35 by ehouzard          #+#    #+#             */
/*   Updated: 2017/12/20 13:50:03 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUF_SIZE 21

typedef struct		s_list
{
	char			tetriminos;
	int				*fig;
	int				width;
	int				height;
	struct s_list	*next;
}					t_list;

typedef	struct		s_adl
{
	t_list *alst;
}					t_adl;

int					ft_error(int ac);
int					ft_error2(void);
int					ft_openclose_file(char *av, t_list *lst);
int					ft_read_file(int fd, t_list *lst, char *buf, int re);
int					ft_check_lastn(char *buf, int re);
int					ft_check_arg(char *buf, int re);
int					ft_check_char(char *buf, int *i, int *dot, int *hash);
void				ft_check_contact(char *buf, int *k, int *contact);
int					ft_fill_coord(t_list *lst, char *buf);
void				ft_fill_fig(int *fig, int *i, int k);
void				ft_coord_fig(int *fig);
void				ft_meas(t_list *lst);
void				ft_putchar(char c);
size_t				ft_strlen(const char *s);
void				ft_putstr(const char *s);
void				ft_putnbr(int n);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
t_list				*ft_lst_tetriminos(void);
void				ft_list_clear(t_list **begin_list);
int					ft_list_size(t_list *begin_list);
char				**ft_sendable(t_list *begin);
int					ft_sqrtfortabsize(int nb);
char				**ft_initialize_tab(int size);
void				ft_free_tab(char **tab);
int					ft_coordtotab(t_list *elem, char **tab, int *i, int size);
void				ft_undocoordtotab(char **tab, t_list *elem, int size);
int					ft_nosegfault_x(int size, t_list *elem, int idx);
int					ft_nosegfault_y(int size, t_list *elem, int *idx);
int					ft_checkpoint(char **tab, int *i, int size);
int					ft_tracking(t_list *elem, char **tab, int i, int size);
void				ft_print_words_tables(char **tab);

#endif
