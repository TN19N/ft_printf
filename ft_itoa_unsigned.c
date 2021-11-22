/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:59:51 by mannouao          #+#    #+#             */
/*   Updated: 2021/11/22 12:58:20 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_num(unsigned int x)
{
	int	i;

	i = 0;
	while (x >= 10)
	{
		i++;
		x /= 10;
	}
	i++;
	return (i);
}

static void	ft_putnum(char *str, unsigned int x, int len_num)
{
	str[len_num] = 0;
	len_num--;
	if (x == 0)
		str[len_num] = '0';
	while (len_num >= 0 && x != 0)
	{
		*(str + len_num) = ((x % 10) + '0');
		x /= 10;
		len_num--;
	}
}

int	ft_itoa_unsigned(unsigned int x)
{
	int				len_num;
	char			*str;
	int				len;

	len_num = ft_len_num(x);
	str = malloc(sizeof(char) * (len_num + 1));
	if (str == NULL)
		return (0);
	ft_putnum(str, x, len_num);
	len = ft_putstr(str);
	free(str);
	return (len);
}
