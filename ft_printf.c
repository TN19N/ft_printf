/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:58:21 by mannouao          #+#    #+#             */
/*   Updated: 2021/11/21 21:59:20 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_if(char c, va_list ptr)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	 if (c == 's')
	 	return (ft_putstr(va_arg(ptr, char *)));
 	if (c == 'p')
  		return (ft_putnbr_base_ad(va_arg(ptr, unsigned long))); 	
	else if (c == 'd')
   		return (ft_itoa(va_arg(ptr, int)));
	else if (c == 'i')
		return (ft_itoa(va_arg(ptr, int)));
	else if (c == 'u')
		return (ft_itoa_unsigned(va_arg(ptr, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base_lower(va_arg(ptr, unsigned int)));
	else if (c == 'X')
		return (ft_putnbr_base_upper(va_arg(ptr, unsigned int)));
	else
		return (ft_putchar(va_arg(ptr, int)));
	return (0);
 }

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;

	len = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += check_if(*str, ptr);
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(ptr);
	return (len);
}
