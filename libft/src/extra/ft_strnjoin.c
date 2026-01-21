/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:34:51 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/15 14:37:09 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnjoin(char *s1, char *s2, ssize_t n, bool free_s1)
{
	char	*result;
	char	*result_base;
	char	*s1_base;

	if (n < 0 || n > ft_strlen(s2))
		result = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	else
		result = ft_calloc((ft_strlen(s1) + n + 1), sizeof(char));
	if (!result)
	{
		if (free_s1)
			free(s1);
		return (NULL);
	}
	result_base = result;
	s1_base = s1;
	while (*s1)
		*(result++) = *(s1++);
	while (*s2 && n-- != 0)
		*(result++) = *(s2++);
	*result = '\0';
	if (free_s1)
		free(s1_base);
	return (result_base);
}