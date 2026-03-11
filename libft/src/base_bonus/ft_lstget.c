/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:47:39 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/11 14:27:47 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_lstget(t_list *list, unsigned int idx)
{
	t_list	*result;

	result = list;
	while (result)
	{
		if (idx == 0)
			return (result->content);
		idx--;
		result = result->next;
	}
	return (NULL);
}
