/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:50:53 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/04 20:02:26 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

void	quit_game(t_game *game)
{
	// mlx_clear_window(game->ctx, game->win);
	// cleanup_images(game);
	mlx_destroy_window(game->ctx, game->win);
	free(game->ctx);
	free(game);
	exit(0);
}

int	handle_keypress(int keycode, void *params)
{
	t_game	*game;
	
	game = (t_game *) params;
	if (keycode == 65307)
		quit_game(game);
	else
	{
		ft_printf("Key pressed: %d. Redrawing.\n", keycode);
		render_objs(game);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 1)
	{
		ft_printf("%sYou need to specify at least 1 map file.%s\n", RED, RST);
		return (1);
	}
	game = new_game(argv[1]);
	render_map(game);
	print_objs(game);
	mlx_key_hook(game->win, &handle_keypress, game);
	return (mlx_loop(game->ctx));
}