/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:33:28 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/19 19:48:26 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	print_lpadding_str(t_conv *conv, int *padding)
{
	int	printed;

	printed = 0;
	if (!(conv->flags & FLAG_LJUSTIFY))
	{
		while (*padding > 0)
		{
			(*padding)--;
			write(1, " ", 1);
			printed++;
		}
	}
	return (printed);
}

int	calculate_padding_str(t_conv *conv, char *val)
{
	int	padding;

	if (conv->flags & FLAG_PRECISION)
		padding = conv->width - ft_min(ft_strlen(val), conv->precision);
	else
		padding = conv->width - ft_strlen(val);
	return (padding);
}
