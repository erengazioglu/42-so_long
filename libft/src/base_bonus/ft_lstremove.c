/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:39:47 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/11 14:28:22 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// like del, but actually updates the original list
// in case you remove the first element
void	ft_lstremove(t_list **lst, t_list *node, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (*lst == node)
		*lst = node->next;
	del(node->content);
	if (node->next && node->prev)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	else if (node->next)
		node->next->prev = NULL;
	else if (node->prev)
		node->prev->next = NULL;
	free(node);
}
