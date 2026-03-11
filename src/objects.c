/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 02:14:34 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/11 14:55:27 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	delete_content(void *content)
{
	free(content);
}

void	destroy_obj(t_game *game, t_obj *obj)
{
	t_list	*node;

	node = ft_lstfind(game->objs, obj);
	if (node)
	{
		render_cell(game, obj->pos[0], obj->pos[1]);
		ft_lstremove(&(game->objs), node, &delete_content);
	}
}

t_obj	*get_obj(t_game *game, int pos[2])
{
	t_list	*list;
	t_obj	*obj;

	list = game->objs;
	while (list)
	{
		obj = (t_obj *) list->content;
		if (obj->pos[0] == pos[0] && obj->pos[1] == pos[1])
			return (obj);
		list = list->next;
	}
	return (NULL);
}

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
	else if (type == 'W')
		obj->anim = game->textures->weapon;
	else if (type == 'K')
		obj->anim = game->textures->key;
	else if (type == 'L')
		obj->anim = game->textures->lock;
}

t_obj	*create_obj(t_game *game, char type, int pos[2])
{
	t_obj	*new_obj;
	t_list	*node;

	if (type == 'P' && game->player)
		return (game->error = MAP_DUPLICATE, NULL);
	new_obj = malloc(sizeof(t_obj));
	if (!new_obj)
		return (game->error = MEM_MALLOC, NULL);
	new_obj->frame = 0;
	new_obj->type = type;
	new_obj->pos[0] = pos[0];
	new_obj->pos[1] = pos[1];
	set_obj_anim(game, new_obj, type);
	if (type == 'P')
		game->player = new_obj;
	else
	{
		node = ft_lstnew(new_obj);
		if (!node)
			return (game->error = MEM_MALLOC, NULL);
		ft_lstadd_back(&(game->objs), node);
		if (type == 'C')
			game->coins++;
	}
	return (new_obj);
}
