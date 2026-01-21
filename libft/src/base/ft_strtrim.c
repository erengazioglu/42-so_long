/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:43:05 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/15 14:40:31 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	check_rest(char const *str, char const *set)
{
	while (*str)
		if (!ft_strchr(set, *(str++)))
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	char	*temp;

	temp = (char *) s1;
	start = 0;
	len = 0;
	while (*temp && ft_strchr(set, *temp))
	{
		start++;
		temp++;
	}
	while (*temp && !check_rest(temp, set))
	{
		len++;
		temp++;
	}
	return (ft_substr(s1, start, len));
}
