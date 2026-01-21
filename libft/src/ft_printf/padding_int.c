/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:31:07 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/19 19:48:08 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	count_chars(int n, int base)
{
	int	count;

	count = 0;
	while (n)
	{
		n /= base;
		count++;
	}
	return (count);
}

void	calculate_padding_int(t_conv *conv, int val, int *zeros, int *padding)
{
	unsigned int	char_count;

	if (ft_strchr("xXp", conv->specifier))
		char_count = count_chars(val, 16);
	else
		char_count = count_chars(val, 10);
	*zeros = 0;
	*padding = conv->width - char_count - ft_isnegative(val);
	if (conv->flags & (FLAG_ZEROPAD | FLAG_PRECISION))
	{
		if (conv->flags & FLAG_PRECISION)
		{
			*zeros = conv->precision - char_count;
			*padding = ft_min(*padding, conv->width - conv->precision);
			if (conv->flags & FLAG_ZEROPAD || conv->precision > char_count)
				*padding -= ft_isnegative(val);
		}
		else
		{
			*zeros = *padding;
			*padding = 0;
		}
	}
}

int	print_lpadding_int(t_conv *conv, int val, int *zeros, int *padding)
{
	int	printed;

	printed = 0;
	if (val == 0 && (conv->flags & FLAG_PRECISION) && conv->precision == 0)
	{
		if (!(conv->flags & FLAG_LJUSTIFY))
			*padding = 0;
		return (0);
	}
	if (!(conv->flags & FLAG_LJUSTIFY))
	{
		while ((*padding)-- > 0)
			printed += ft_putstr_n(" ", 1);
	}
	if (!ft_strchr("xXpu", conv->specifier))
	{
		if (val < 0)
			printed += ft_putstr_n("-", 1);
		else if (conv->flags & FLAG_SIGN)
			printed += ft_putstr_n("+", 1);
	}
	while ((*zeros)-- > 0)
		printed += ft_putstr_n("0", 1);
	return (printed);
}

int	print_rpadding_int(t_conv *conv, int *padding)
{
	int	printed;

	printed = 0;
	if (conv->flags & FLAG_LJUSTIFY)
	{
		while ((*padding)-- > 0)
			printed += ft_putstr_n(" ", 1);
	}
	return (printed);
}
