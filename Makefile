# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 17:23:46 by mannouao          #+#    #+#              #
#    Updated: 2021/11/21 17:53:20 by mannouao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_itoa_unsigned.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_putnbr_base_ad.c\
		ft_putnbr_base_lower.c\
		ft_putnbr_base_upper.c\
		ft_putstr.c\
		ft_strlen.c\
		ft_strlen_num.c\
		ft_strlen.c\
		ft_printf.c

OBJS = $(SRCS:.c=.o)
CC = gcc
NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.c : %.o
	$(CC) $(FLAGS) -c $<

clean :
	rm -f $(OBJS)
	
fclean : clean
	rm -f $(NAME)

re : fclean all