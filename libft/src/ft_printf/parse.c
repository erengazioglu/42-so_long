/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:25:03 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/19 19:48:25 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

t_conv	*new_conv(void)
{
	t_conv	*conv;

	conv = ft_calloc(1, sizeof(t_conv));
	if (!conv)
		return (NULL);
	return (conv);
}

const char	*parse_flag(const char *str, t_conv *conv)
{
	if (*str == '+' && !(conv->flags & FLAG_SIGN))
		conv->flags |= FLAG_SIGN;
	else if (*str == '-' && !(conv->flags & FLAG_LJUSTIFY))
		conv->flags |= FLAG_LJUSTIFY;
	else if (*str == '0' && !(conv->flags & FLAG_ZEROPAD))
		conv->flags |= FLAG_ZEROPAD;
	else if (*str == ' ' && !(conv->flags & FLAG_SPACE))
		conv->flags |= FLAG_SPACE;
	else if (*str == '#' && !(conv->flags & FLAG_ALTERNATE))
		conv->flags |= FLAG_ALTERNATE;
	return (++str);
}

const char	*parse_precision(const char *str, t_conv *conv)
{
	int	precision;

	precision = ft_atoi(++str);
	conv->flags |= FLAG_PRECISION;
	conv->precision = precision;
	while (*str && ft_isdigit(*str))
		str++;
	return (str);
}

const char	*parse_num(const char *str, unsigned int *ptr)
{
	*ptr = ft_atoi(str);
	while (*str && ft_isdigit(*str))
		str++;
	return (str);
}

// assumes the format string is valid!
// checks are made in the program that reads the fstring
t_conv	*parse_conv(const char **str)
{
	t_conv	*conv;

	conv = new_conv();
	if (!conv)
		return (NULL);
	while (**str && !ft_strchr("cspdiuxX%", **str))
	{
		if (ft_strchr("-0+ #", **str))
			*str = parse_flag(*str, conv);
		else if (**str == '.')
			*str = parse_precision(*str, conv);
		else if (ft_isdigit(**str))
			*str = parse_num(*str, &(conv->width));
		else
			return (conv);
	}
	conv->specifier = *(*str)++;
	return (conv);
}
