/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:47:02 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/15 14:40:31 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	if (!dstsize)
		return (ft_strlen(src));
	len = ft_strlen(dst);
	if (len > dstsize)
		len = dstsize;
	len += ft_strlen(src);
	while (*dst)
	{
		if (dstsize)
			dstsize--;
		dst++;
	}
	while (*src)
	{
		if (dstsize > 1)
		{
			*(dst++) = *src;
			dstsize--;
		}
		src++;
	}
	*dst = 0;
	return (len);
}
