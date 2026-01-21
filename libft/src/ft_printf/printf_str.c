/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:46:27 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/19 19:48:41 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	printf_str(t_conv *conv, void *val)
{
	int		padding;
	int		printed;

	padding = calculate_padding_str(conv, val);
	printed = print_lpadding_str(conv, &padding);
	if (conv->flags & FLAG_PRECISION)
		printed += ft_putstr_n(val, conv->precision);
	else
		printed += ft_putstr_n(val, -1);
	while (padding > 0)
	{
		padding--;
		write(1, " ", 1);
		printed++;
	}
	return (printed);
}
