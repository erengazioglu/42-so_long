/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:50:53 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/05 10:52:13 by egaziogl         ###   ########.fr       */
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

int	process(void *param)
{
	t_game	*game;
	long	time;

	game = (t_game *) param;
	time = current_time_ms();
	if ((int) time - game->last_update > 100)
	{
		game->last_update = time;
		render_objs(game);
	}
	return (0);
}

int	handle_keypress(int keycode, void *param)
{
	t_game	*game;
	e_key	key;
	
	game = (t_game *) param;
	key = get_key_input(keycode);
	if (key == QUIT)
		quit_game(game);
	else if (key != NOKEY)
		player_action(game, key);
	else
		ft_printf("Key pressed: %d.\n", key);
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
	mlx_key_hook(game->win, &handle_keypress, game);
	mlx_loop_hook(game->ctx, &process, game);
	return (mlx_loop(game->ctx));
}