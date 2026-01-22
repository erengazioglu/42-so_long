/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:50:53 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/22 00:40:47 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*window;
	void	*wall;
	void	*empty;
	void	*exit;
	int		w;
	int		h;
	
	mlx = mlx_init();
	window = mlx_new_window(
		mlx, 
		10 * GRID_SIZE * GRID_MULT,
		10 * GRID_SIZE * GRID_MULT, 
		"Hello!"
	);
	wall = mlx_xpm_file_to_image(mlx, "assets/wall-01_x3.xpm", &w, &h);
	empty = mlx_xpm_file_to_image(mlx, "assets/empty-01_x3.xpm", &w, &h);
	exit = mlx_xpm_file_to_image(mlx, "assets/exit-01-x3.xpm", &w, &h);
	if (!wall)
	{
		ft_printf("Malloc error, quitting\n");
		return (free(mlx), free(window), 1);
	}
	for (int x = 0; x < 10; x++)
	{
		mlx_put_image_to_window(mlx, window, wall, w * x, 0);
		mlx_put_image_to_window(mlx, window, wall, w * x, w * 9);
	}
	for (int y = 1; y < 9; y++)
	{
		mlx_put_image_to_window(mlx, window, wall, 0, w * y);
		mlx_put_image_to_window(mlx, window, wall, w * 9, w * y);
	}
	for (int x = 1; x < 9; x++)
	{
		for (int y = 1; y < 9; y++)
			mlx_put_image_to_window(mlx, window, empty, w * x, w * y);
	}
	mlx_put_image_to_window(mlx, window, exit, w * 8, w);
	

	return (mlx_loop(mlx));
}