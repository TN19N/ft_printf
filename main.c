/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:08:24 by mannouao          #+#    #+#             */
/*   Updated: 2021/11/21 03:59:08 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}


void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void get_heax(int a)
{
	char hex[] = "0123456789abcdef";
	if(a <= 16)
	{
		ft_putstr_fd("0x", 1);
		ft_putchar_fd(hex[a], 1);
	}
	if(a > 16)
	{
		get_heax(a / 16);
		ft_putchar_fd(hex[a % 16], 1);
	}
}

int ft_strlen_hex(int i)
{
	int count;

	count = 2;
	while(i > 16)
	{
		i /= 16;
		count++;
	}
	count++;
	return (count);
}

int ft_strlen_num(int i)
{
	int count;

	count  = 0;
	while(i > 10)
	{
		i /= 10;
		count++;
	}
	count++;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	
	char c;
	char *s;
	int i;
	int addr;
	int count = 0;
	va_list ptr;

	va_start(ptr, str);
	while(*str)
	{
		if(*str == '%')
		{
			str++;
			if(*str == 'c')
			{
				c = va_arg(ptr, int);
				ft_putchar_fd(c, 1);
				count++;
			}
			else if(*str == 's')
			{
				s = va_arg(ptr, char *);
				ft_putstr_fd(s, 1);
				count += ft_strlen(s);
			}
			else if(*str == 'p')
			{
				addr = va_arg(ptr, int);
				get_heax(addr);
				count += ft_strlen_hex(addr);
			}
			else if(*str == 'd')
			{
				i = va_arg(ptr, int);
				ft_putnbr_fd(i, 1);
				count += ft_strlen_num(i);
			}
			else if(*str == 'i')
			{
				
			}
			else if(*str == 'u')
			{
				
			}
			else if(*str == 'x')
			{
				
			}
			else if(*str == 'X')
			{
				
			}
			else
			{
				ft_putchar_fd(*str, 1);
				count++;
			}
		}
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	va_end(ptr);
	return(count);
}

int main(void)
{
	void *str;
	ft_printf("{%d}", ft_printf("num => %p", str));
	ft_printf("\n||||||||||||||||||||||||||||||||||||||\n");
	printf("{%d}", printf("num => %x", str));
}