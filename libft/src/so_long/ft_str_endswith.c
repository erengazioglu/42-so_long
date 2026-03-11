/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_endswith.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:05:31 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/11 15:26:53 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

bool	ft_str_endswith(char *str, char *test)
{
	int	len;

	len = ft_strlen(test);
	if (ft_strlen(str) < ft_strlen(test))
		return (false);
	while (*str)
		str++;
	while (*test)
		test++;
	while (len--)
	{
		if (*(--str) != *(--test))
			return (false);
	}
	return (true);
}
