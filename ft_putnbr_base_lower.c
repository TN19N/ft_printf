/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_lower.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:08:08 by mannouao          #+#    #+#             */
/*   Updated: 2021/11/21 22:03:51 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	base_recurtion(unsigned long i, char *base)
{
	if (i < 16)
	{
		ft_putchar(base[i]);
	}
	else
	{
		base_recurtion(i / 16, base);
		ft_putchar(base[i % 16]);
	}
}

int	ft_putnbr_base_lower(unsigned long i)
{
	int	count;
	char *base;
	int	j;

	j = 0;
	base = malloc(sizeof(char) * 16);
	while(j < 16)
	{
		if(j < 10)
			base[j] = 48 + j;
		else
			base[j] = 87 + j;
		j++; 
	}
	base[j] = '\0';
	count = 0;
	base_recurtion(i, base);
	while (i >= 16)
	{
		i /= 16;
		count++;
	}
	count++;
	free(base);
	return (count);
}
