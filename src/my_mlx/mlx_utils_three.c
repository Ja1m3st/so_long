/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:47:12 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/04 15:52:52 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_gamedata	*game;

	game = (t_gamedata *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W)
			move_player(game, 0, -1);
		else if (keydata.key == MLX_KEY_S)
			move_player(game, 0, 1);
		else if (keydata.key == MLX_KEY_A)
			move_player(game, -1, 0);
		else if (keydata.key == MLX_KEY_D)
			move_player(game, 1, 0);
		else if (keydata.key == MLX_KEY_ESCAPE)
			exit(EXIT_SUCCESS);
	}
}
