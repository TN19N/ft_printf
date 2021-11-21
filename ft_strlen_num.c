/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:45:33 by mannouao          #+#    #+#             */
/*   Updated: 2021/11/21 18:38:59 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_num(int i)
{
	int				count;
	unsigned int	tmp;

	count = 0;
	if (i < 0)
	{
		count++;
		tmp = -i;
	}
	else
		tmp = i;
	while (tmp >= 10)
	{
		tmp /= 10;
		count++;
	}
	count++;
	return (count);
}
