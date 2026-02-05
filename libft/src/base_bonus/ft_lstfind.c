/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 02:13:51 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/05 10:40:34 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// return the element that has the same content (void *)
t_list	*ft_lstfind(t_list *list, void *content)
{
	t_list	*result;

	result = list;
	while (result)
	{
		if (result->content == content)
			return (result);
		result = result->next;
	}
	return (NULL);
}