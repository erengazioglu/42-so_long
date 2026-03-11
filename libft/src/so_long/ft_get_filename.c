/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_filename.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:57:32 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/11 15:27:04 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_get_filename(char *str)
{
	char	*retval;

	retval = str;
	while (*str)
	{
		if (*str == '/' && *(str + 1) && *(str + 1) != '/')
			retval = str + 1;
		str++;
	}
	return (retval);
}
