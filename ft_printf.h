/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:11:22 by mannouao          #+#    #+#             */
/*   Updated: 2021/11/22 13:12:38 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_strlen(char *str);
int	ft_putchar(char c);
int	ft_strlen_num(int i);
int	ft_itoa(int a);
int	ft_putstr(char *str);
int	ft_putnbr_base_ad(unsigned long i);
int	ft_itoa_unsigned(unsigned int x);
int	ft_putnbr_base_lower(unsigned long i);
int	ft_putnbr_base_upper(unsigned long i);

#endif