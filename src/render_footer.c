/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_footer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 09:24:24 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/09 14:57:39 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	clear_square(t_game *game, int x, int y, int size[2])
{
	int	x_temp;

	// start from x, y
	// paint x+1, y | x+2, y | so on 
	while (size[1] > 0)
	{
		x_temp = size[0];
		while (x_temp > 0)
			mlx_pixel_put(game->ctx, game->win,
				x + x_temp--, y + size[1], MLX_BLACK);
		size[1]--;
	}
}

bool	render_footer(t_game *game)
{
	char	*count;
	int		clear_size[2];

	count = ft_itoa(game->moves);
	if (!count)
		return (game->error = MEM_MALLOC, false);
	ft_printf("%sTotal moves: %s\n%s", YEL, count, RST);
	clear_size[0] = GRID_MULT * GRID_SIZE;
	clear_size[1] = 24;
	clear_square(game, 
		14 + GRID_MULT * GRID_SIZE, 
		(game->map_size[1]) * GRID_MULT * GRID_SIZE,
		clear_size
	);
	mlx_string_put(game->ctx, game->win,
		16 + GRID_MULT * GRID_SIZE,
		(game->map_size[1]) * GRID_MULT * GRID_SIZE + 16,
		MLX_WHITE,
		count
	);
	return (free(count), true);
}
