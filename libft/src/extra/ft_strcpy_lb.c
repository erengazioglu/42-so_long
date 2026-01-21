/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_lb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:37:42 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/15 14:38:00 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strcpy_lb(char *dst, char *src, char delim, bool lb)
{
	while (*src != delim)
		*dst++ = *src++;
	if (lb)
		*dst++ = '\n';
	*dst = '\0';
	return (dst);
}