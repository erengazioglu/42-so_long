/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:51:19 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/24 14:54:37 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstprint(t_list *lst)
{
	t_list *node;

	node = lst;
	if (!node)
		ft_printf("%sList is empty/null.%s\n", YEL, RST);
	while (node)
	{
		ft_printf("Node: %p || Prev %p, Next %p\n", node, node->prev, node->next);
		node = node->next;
	}
}