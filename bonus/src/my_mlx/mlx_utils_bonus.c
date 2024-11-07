/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:22 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/06 13:36:04 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

mlx_t	*initialize_window(int width, int height)
{
	mlx_t	*mlx;

	mlx = mlx_init(width * 64, height * 64, "so_long", true);
	if (!mlx)
		ft_error();
	return (mlx);
}

void	load_textures(t_textures *t_textures)
{
	t_textures->floor = mlx_load_png("./bonus/src/imgs/Floor.png");
	t_textures->pj = mlx_load_png("./bonus/src/imgs/Pj2.png");
	t_textures->wall = mlx_load_png("./bonus/src/imgs/Wall.png");
	t_textures->heart = mlx_load_png("./bonus/src/imgs/heart.png");
	t_textures->exit = mlx_load_png("./bonus/src/imgs/Exit2.png");
	t_textures->ghost = mlx_load_png("./bonus/src/imgs/Ghost.png");
}

void	textures_to_images(mlx_t *mlx, t_textures *t_textures,
		t_images *t_images)
{
	t_images->floor = mlx_texture_to_image(mlx, t_textures->floor);
	t_images->pj = mlx_texture_to_image(mlx, t_textures->pj);
	t_images->wall = mlx_texture_to_image(mlx, t_textures->wall);
	t_images->heart = mlx_texture_to_image(mlx, t_textures->heart);
	t_images->exit = mlx_texture_to_image(mlx, t_textures->exit);
	t_images->ghost = mlx_texture_to_image(mlx, t_textures->ghost);
}

void	initialize_enemy(t_enemy *enemy, mlx_t *mlx)
{
	enemy->frames_text[0] = mlx_load_png
		("./bonus/src/imgs/anim/SwordSkelet-outline1.png");
	enemy->frames_text[1] = mlx_load_png
		("./bonus/src/imgs/anim/SwordSkelet-outline2.png");
	enemy->frames_text[2] = mlx_load_png
		("./bonus/src/imgs/anim/SwordSkelet-outline3.png");
	enemy->frames_text[3] = mlx_load_png
		("./bonus/src/imgs/anim/SwordSkelet-outline4.png");
	enemy->frames_png[0] = mlx_texture_to_image(mlx, enemy->frames_text[0]);
	enemy->frames_png[1] = mlx_texture_to_image(mlx, enemy->frames_text[1]);
	enemy->frames_png[2] = mlx_texture_to_image(mlx, enemy->frames_text[2]);
	enemy->frames_png[3] = mlx_texture_to_image(mlx, enemy->frames_text[3]);
	enemy->mlx = mlx;
	enemy->frame_index = 0;
	enemy->animation_counter = 0;
}
