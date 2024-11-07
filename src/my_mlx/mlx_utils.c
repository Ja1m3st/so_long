/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:22 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/06 13:00:41 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	ft_printf("Error");
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
	t_textures->floor = mlx_load_png("./src/imgs/Floor.png");
	t_textures->pj = mlx_load_png("./src/imgs/Pj2.png");
	t_textures->wall = mlx_load_png("./src/imgs/Wall.png");
	t_textures->heart = mlx_load_png("./src/imgs/heart.png");
	t_textures->exit = mlx_load_png("./src/imgs/Exit2.png");
}

void	textures_to_images(mlx_t *mlx, t_textures *t_textures,
		t_images *t_images)
{
	t_images->floor = mlx_texture_to_image(mlx, t_textures->floor);
	t_images->pj = mlx_texture_to_image(mlx, t_textures->pj);
	t_images->wall = mlx_texture_to_image(mlx, t_textures->wall);
	t_images->heart = mlx_texture_to_image(mlx, t_textures->heart);
	t_images->exit = mlx_texture_to_image(mlx, t_textures->exit);
}

void	data_game(t_gamedata *game, char **map, mlx_t *mlx, t_images t_images)
{
	int			start_x;
	int			start_y;

	start_x = 0;
	start_y = 0;
	ft_find_p(map, &start_x, &start_y);
	game->player_x = start_x;
	game->player_y = start_y;
	game->mlx = mlx;
	game->map = map;
	game->images = t_images;
	game->colls = ft_find_cs(map);
	game->exit = 0;
	mlx_image_to_window(mlx, game->images.pj, start_x * 64, start_y * 64);
}
