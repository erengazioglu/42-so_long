/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:33:12 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/15 16:26:50 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	print_conv(t_conv *conv, va_list *args)
{
	if (conv->specifier == 'c')
		return (printf_char(conv, va_arg(*args, int)));
	else if (conv->specifier == 's')
		return (printf_str(conv, va_arg(*args, void *)));
	else if (conv->specifier == 'i' || conv->specifier == 'd')
		return (printf_int(conv, va_arg(*args, int)));
	else if (conv->specifier == 'x' || conv->specifier == 'X')
		return (printf_hex(conv, va_arg(*args, unsigned int)));
	else if (conv->specifier == 'u')
		return (printf_uint(conv, va_arg(*args, unsigned int)));
	else if (conv->specifier == 'p')
		return (printf_ptr(conv, va_arg(*args, void *)));
	else if (conv->specifier == '%')
		return (printf_percent());
	return (0);
}

static int	is_conv_valid(const char *str)
{
	char	c;

	if (*str == '%')
		return (1);
	while (*str && !ft_strchr("csidxXup", *str))
	{
		c = *(str++);
		if (!ft_strchr("-0123456789+ #.", c))
			return (0);
		while (*str && *str == c)
			str++;
	}
	if (ft_strchr("csidxXup", *str))
		return (1);
	return (0);
}

static t_conv	*handle_conv(const char **fstr, va_list *args, int *printed)
{
	t_conv	*conv;

	conv = parse_conv(fstr);
	if (!conv)
	{
		va_end(*args);
		return (NULL);
	}
	*printed += print_conv(conv, args);
	return (conv);
}

int	ft_printf(const char *fstr, ...)
{
	va_list	args;
	int		printed;
	t_conv	*conv;

	printed = 0;
	va_start(args, fstr);
	while (*fstr)
	{
		if (*fstr == '%' && is_conv_valid(fstr + 1))
		{
			fstr++;
			conv = handle_conv(&fstr, &args, &printed);
			if (!conv)
				return (-1);
			free(conv);
			conv = NULL;
		}
		else
		{
			write(1, fstr++, 1);
			printed++;
		}
	}
	va_end(args);
	return (printed);
}
