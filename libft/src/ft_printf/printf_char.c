/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:54:06 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/19 19:48:25 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	printf_char(t_conv *conv, char val)
{
	int	padding;
	int	printed;

	padding = conv->width - 1;
	printed = 0;
	if (!(conv->flags & FLAG_LJUSTIFY))
	{
		while (padding-- > 0)
		{
			printed++;
			write(1, " ", 1);
		}
	}
	ft_putchar(val);
	printed++;
	while (padding > 0)
	{
		padding--;
		printed++;
		write(1, " ", 1);
	}
	return (printed);
}
