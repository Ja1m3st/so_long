/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_three_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:47:12 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/06 16:13:17 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize_nums(t_gamedata *game, mlx_t *mlx)
{
	game->nums_text[0] = mlx_load_png("./bonus/src/imgs/nums/0.png");
	game->nums_text[1] = mlx_load_png("./bonus/src/imgs/nums/1.png");
	game->nums_text[2] = mlx_load_png("./bonus/src/imgs/nums/2.png");
	game->nums_text[3] = mlx_load_png("./bonus/src/imgs/nums/3.png");
	game->nums_text[4] = mlx_load_png("./bonus/src/imgs/nums/4.png");
	game->nums_text[5] = mlx_load_png("./bonus/src/imgs/nums/5.png");
	game->nums_text[6] = mlx_load_png("./bonus/src/imgs/nums/6.png");
	game->nums_text[7] = mlx_load_png("./bonus/src/imgs/nums/7.png");
	game->nums_text[8] = mlx_load_png("./bonus/src/imgs/nums/8.png");
	game->nums_text[9] = mlx_load_png("./bonus/src/imgs/nums/9.png");
	game->nums_png[0] = mlx_texture_to_image(mlx, game->nums_text[0]);
	game->nums_png[1] = mlx_texture_to_image(mlx, game->nums_text[1]);
	game->nums_png[2] = mlx_texture_to_image(mlx, game->nums_text[2]);
	game->nums_png[3] = mlx_texture_to_image(mlx, game->nums_text[3]);
	game->nums_png[4] = mlx_texture_to_image(mlx, game->nums_text[4]);
	game->nums_png[5] = mlx_texture_to_image(mlx, game->nums_text[5]);
	game->nums_png[6] = mlx_texture_to_image(mlx, game->nums_text[6]);
	game->nums_png[7] = mlx_texture_to_image(mlx, game->nums_text[7]);
	game->nums_png[8] = mlx_texture_to_image(mlx, game->nums_text[8]);
	game->nums_png[9] = mlx_texture_to_image(mlx, game->nums_text[9]);
}

void	data_game(t_gamedata *game, char **map, mlx_t *mlx, t_images t_images)
{
	int			start_x;
	int			start_y;
	t_enemy		enemy;

	start_x = 0;
	start_y = 0;
	ft_find_p(map, &start_x, &start_y);
	game->mlx = mlx;
	initialize_enemy(&enemy, mlx);
	initialize_nums(game, mlx);
	game->player_x = start_x;
	game->player_y = start_y;
	game->map = map;
	game->images = t_images;
	game->colls = ft_find_cs(map);
	game->exit = 0;
	game->enemy = enemy;
	mlx_image_to_window(mlx, game->images.pj, start_x * 64, start_y * 64);
}

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
