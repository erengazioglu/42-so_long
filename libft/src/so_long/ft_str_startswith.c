/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_startswith.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:35:51 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/09 17:36:52 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

bool	ft_str_startswith(char *str, char *test)
{
	while (*str && *test)
	{
		if (*(str++) != *(test++))
			return (false);
	}
	if (*test)
		return (false);
	return (true);
}
