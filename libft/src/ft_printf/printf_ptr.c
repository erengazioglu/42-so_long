/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:30:34 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/19 19:48:38 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	printf_ptr(t_conv *conv, void *val)
{
	int				zeros;
	int				padding;
	int				printed;
	unsigned long	cast;

	printed = 0;
	cast = (unsigned long) val;
	calculate_padding_int(conv, cast, &zeros, &padding);
	printed += print_lpadding_int(conv, cast, &zeros, &padding);
	if (val == NULL)
		printed += ft_putstr_n("(nil)", -1);
	else
	{
		printed += ft_putstr_n("0x", -1);
		printed += ft_putstr_n(ft_itoa_base(cast, "0123456789abcdef"), -1);
	}
	printed += print_rpadding_int(conv, &padding);
	return (printed);
}
// #include <stdio.h>

// int main(void)
// {
// 	printf("hey");
// }