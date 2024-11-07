/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:08:35 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/06 13:04:39 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(mlx_t *mlx, t_textures *textures, t_images *images)
{
	mlx_delete_texture(textures->wall);
	mlx_delete_texture(textures->exit);
	mlx_delete_texture(textures->pj);
	mlx_delete_texture(textures->heart);
	mlx_delete_texture(textures->floor);
	mlx_delete_image(mlx, images->wall);
	mlx_delete_image(mlx, images->exit);
	mlx_delete_image(mlx, images->pj);
	mlx_delete_image(mlx, images->heart);
	mlx_delete_image(mlx, images->floor);
}

int64_t	main_mlx(char **map)
{
	mlx_t		*mlx;
	t_textures	t_textures;
	t_images	t_images;
	t_gamedata	game;

	mlx = initialize_window(cont_colum(map), cont_row(map));
	if (!mlx)
		ft_error();
	load_textures(&t_textures);
	textures_to_images(mlx, &t_textures, &t_images);
	render_map(mlx, map, &t_images);
	data_game(&game, map, mlx, t_images);
	mlx_key_hook(mlx, key_press, &game);
	mlx_loop(mlx);
	free_all(mlx, &t_textures, &t_images);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
