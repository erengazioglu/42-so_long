/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:19:52 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/15 14:40:31 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	count_chars(unsigned int n)
{
	int	count;

	if (!n)
		return (1);
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	copy_digits(unsigned int n, char *s, int len)
{
	s += len - 1;
	while (n)
	{
		*(s--) = '0' + (n % 10);
		n /= 10;
	}
}

char	*ft_itoa_uint(unsigned int n)
{
	char	*result;
	int		len;

	len = count_chars(n);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (n == 0)
	{
		*result = '0';
		*(result + 1) = '\0';
	}
	else
		copy_digits(n, result, len);
	return (result);
}
