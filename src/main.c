/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:50:53 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/22 00:22:31 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*window;
	void	*wall;
	int		w;
	int		h;
	
	mlx = mlx_init();
	window = mlx_new_window(
		mlx, 
		10 * GRID_SIZE * GRID_MULT,
		10 * GRID_SIZE * GRID_MULT, 
		"Hello!"
	);
	wall = mlx_xpm_file_to_image(mlx, "assets/wall-01-x3.xpm", &w, &h);
	if (!wall)
	{
		ft_printf("Malloc error, quitting\n");
		return (free(mlx), free(window), 1);
	}
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			mlx_put_image_to_window(mlx, window, wall, w * x, w * y);
		}
	}

	return (mlx_loop(mlx));
}