/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 00:40:24 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/07 06:17:07 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_error(t_game *game)
{
	e_err	err;
	
	ft_printf("%sError:\n", RED);
	if (!game)
	{
		ft_printf("Couldn't allocate memory for the game.%s\n", RST);
		return;
	}
	err = game->error;
	if (err == MEM_MALLOC)
		ft_printf("Memory allocation failed.%s\n", RST);
	else if (err == MAP_READ_ERROR || err == MAP_INVALID_FILEPATH)
		ft_printf("Couldn't read file.%s\n", RST);
	else if (err == MAP_INVALID_BOUNDARY)
		ft_printf("Map is not enclosed in walls.%s\n", RST);
	else if (err == MAP_INVALID_ROW_LENGTH)
		ft_printf("Map is not rectangular.%s\n", RST);
}

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_size[1])
		ft_printf("%s", (game->map)[i++]);
	ft_printf("\n");
}

void	print_objs(t_game *game)
{
	t_list	*objs;
	t_obj	*curr;

	ft_printf("Player: (%d, %d)\n", game->player->pos[0], game->player->pos[1]);
	objs = game->objs;
	while (objs->next)
	{
		curr = (t_obj *) objs->content;
		ft_printf(
			"Object [%c]: (%d, %d)\n", curr->type, curr->pos[0], curr->pos[1]
		);
		objs = objs->next;
	}
	curr = (t_obj *) objs->content;
	ft_printf(
		"Object [%c]: (%d, %d)\n", curr->type, curr->pos[0], curr->pos[1]
	);
}