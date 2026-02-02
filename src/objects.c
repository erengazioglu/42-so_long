/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 02:14:34 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/02 02:44:15 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_obj	*create_obj(t_game *game, char type, int pos[2])
{
	t_obj	*new_obj;

	new_obj = malloc(sizeof(t_obj));
	if (!new_obj)
		return (NULL);
	new_obj->frame = 0;
	new_obj->type = type;
	new_obj->pos[0] = pos[0];
	new_obj->pos[1] = pos[1];
	ft_lstadd_back(&(game->objs), ft_lstnew(new_obj));
	return (new_obj);
}