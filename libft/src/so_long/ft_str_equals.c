/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_equals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:12:03 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/09 18:18:53 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

bool	ft_str_equals(char *str, char *test)
{
	ft_printf("comparing: %s and %s\n", str, test);
	while (*str && *test)
	{
		if (*(str++) != *(test++))
			return (false);
	}
	if (*test || *str)
		return (false);
	return (true);
}