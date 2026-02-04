/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:57:58 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/05 00:40:03 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

e_key	get_key_input(int keycode)
{
	if (keycode == 65307)
		return (QUIT);
	else if (keycode == 65363 || keycode == 100)
		return (E);
	else if (keycode == 65364 || keycode == 115)
		return (S);
	else if (keycode == 65361 || keycode == 97)
		return (W);
	else if (keycode == 65362 || keycode == 119)
		return (N);
	return (NOKEY);
}