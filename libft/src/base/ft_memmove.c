/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:01:57 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/15 14:40:31 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*temp;

	temp = dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		dest += n - 1;
		src += n - 1;
	}
	while (n--)
	{
		if (dest > src)
			*((unsigned char *) dest--) = *((unsigned char *) src--);
		else
			*((unsigned char *) dest++) = *((unsigned char *) src++);
	}
	return (temp);
}
