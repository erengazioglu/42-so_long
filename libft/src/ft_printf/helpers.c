/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:39:44 by egaziogl          #+#    #+#             */
/*   Updated: 2025/12/14 14:30:56 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr_n(const char *str, int n)
{
	int	i;

	i = 0;
	while (*str && n)
	{
		n--;
		i++;
		write(1, str++, 1);
	}
	return (i);
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

int	ft_min(int i1, int i2)
{
	if (i1 > i2)
		return (i2);
	return (i1);
}

int	ft_isnegative(int i)
{
	return (i < 0);
}
