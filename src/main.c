/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:50:53 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/09 14:17:35 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

void	crash(t_game *game)
{
	print_error(game);
	cleanup(game);
	exit(1);
}

void	quit_game(t_game *game)
{
	cleanup(game);
	exit(0);
}

int	process(void *param)
{
	t_game	*game;
	long	time;

	game = (t_game *) param;
	time = current_time_ms();
	if ((int) time - game->last_update > 1000 / REFRESH_RATE)
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
	if (key == KEY_QUIT || game->dead)
		quit_game(game);
	else if (key != KEY_NONE)
		player_action(game, key);
	else
		ft_printf("Key pressed: %d.\n", key);
	render_footer(game);
	return (0);
}

int	handle_close(void *param)
{
	t_game *game;

	game = (t_game *) param;
	quit_game(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("%sError:\nYou need to specify 1 map file as an argument.%s\n",
			RED, RST);
		return (1);
	}
	game = new_game(argv[1]);
	if (!game)
		crash(game);
	mlx_key_hook(game->win, &handle_keypress, game);
	mlx_hook(game->win, BTN_EXIT, 0L, &handle_close, game);
	mlx_loop_hook(game->ctx, &process, game);
	return (mlx_loop(game->ctx));
}