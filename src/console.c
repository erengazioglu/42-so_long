/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 00:40:24 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/06 14:54:23 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_error(t_game *game)
{
	ft_printf("%sError:\n", RED);
	if (!game)
		ft_printf("Couldn't allocate memory for the game.%s\n", RST);
	else if (game->error == MEM_MALLOC)
		ft_printf("Memory allocation failed.%s\n", RST);
	else if (game->error == MAP_READ_ERROR)
		ft_printf("Couldn't read file.%s\n", RST);

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