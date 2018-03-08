# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esouza <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 12:38:55 by esouza            #+#    #+#              #
#    Updated: 2017/12/19 16:08:39 by esouza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror

CC = gcc -Ifillit.h

SRCS = main.c checkup.c lstthings.c ft_putnbr.c solver.c coordfig.c ft_memalloc.c ft_putstr.c \
	   ft_strlen.c array.c error.c ft_putchar.c read_file.c ft_strnew.c

OBJS = main.o checkup.o lstthings.o ft_putnbr.o solver.o coordfig.o ft_memalloc.o ft_putstr.o \
	   ft_strlen.o array.o error.o ft_putchar.o read_file.o ft_strnew.o

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
