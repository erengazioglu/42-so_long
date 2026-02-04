/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 02:14:34 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/04 20:39:35 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_obj_anim(t_game *game, t_obj *obj, char type)
{
	if (type == 'P')
		obj->anim = game->textures->player;
	else if (type == 'C')
		obj->anim = game->textures->coin;
	else if (type == 'X')
		obj->anim = game->textures->slime;
	else if (ft_strchr("^>v<", type))
		obj->anim = game->textures->bat;
}

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
	set_obj_anim(game, new_obj, type);
	if (type == 'P')
		game->player = new_obj;
	else if (type == 'E')
		game->exit = new_obj;
	else
		ft_lstadd_back(&(game->objs), ft_lstnew(new_obj));
	return (new_obj);
}
