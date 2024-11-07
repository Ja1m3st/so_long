/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_two_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:15 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/06 16:36:25 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_map(mlx_t *mlx, char **map, t_images *t_images)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cont_colum(map))
	{
		while (j < cont_row(map))
		{
			mlx_image_to_window(mlx, t_images->floor, i * 64, j * 64);
			if (map[j][i] == '1')
				mlx_image_to_window(mlx, t_images->wall, i * 64, j * 64);
			else if (map[j][i] == 'C')
				mlx_image_to_window(mlx, t_images->heart, i * 64, j * 64);
			else if (map[j][i] == 'E')
				mlx_image_to_window(mlx, t_images->exit, i * 64, j * 64);
			j++;
		}
		j = 0;
		i++;
	}
}

void	put_before(t_gamedata *game)
{
	if (game->map[game->player_y][game->player_x] == '0'
		|| game->map[game->player_y][game->player_x] == 'P')
		mlx_image_to_window(game->mlx, game->images.floor,
			game->player_x * 64, game->player_y * 64);
	else if (game->map[game->player_y][game->player_x] == 'E')
	{
		mlx_image_to_window(game->mlx, game->images.floor,
			game->player_x * 64, game->player_y * 64);
		mlx_image_to_window(game->mlx, game->images.exit,
			game->player_x * 64, game->player_y * 64);
	}
	else if (game->map[game->player_y][game->player_x] == 'C')
	{
		mlx_image_to_window(game->mlx, game->images.floor,
			game->player_x * 64, game->player_y * 64);
	}
	else if (game->map[game->player_y][game->player_x] == 'N')
	{
		mlx_image_to_window(game->mlx, game->images.floor,
			game->player_x * 64, game->player_y * 64);
	}
}

int	put_after(t_gamedata *game, int new_y, int new_x, int collects)
{
	game->player_x = new_x;
	game->player_y = new_y;
	if (game->map[new_y][new_x] == '0' || game->map[new_y][new_x] == 'P')
	{
		mlx_image_to_window(game->mlx, game->images.pj,
			game->player_x * 64, game->player_y * 64);
	}
	else if (game->map[new_y][new_x] == 'E')
	{
		if (game->exit == 1)
			exit(EXIT_SUCCESS);
		mlx_image_to_window(game->mlx, game->images.pj,
			game->player_x * 64, game->player_y * 64);
	}
	else if (game->map[new_y][new_x] == 'C')
	{
		mlx_image_to_window(game->mlx, game->images.pj,
			game->player_x * 64, game->player_y * 64);
		game->map[new_y][new_x] = '0';
		collects++;
	}
	else if (game->map[new_y][new_x] == 'N')
		exit(EXIT_SUCCESS);
	return (collects);
}

void	put_nums(t_gamedata *game, int movs)
{
	int	digit;
	int	pos_x;

	pos_x = 2 * 64;
	if (movs == 0)
	{
		mlx_image_to_window(game->mlx, game->images.wall, pos_x, 0);
		mlx_image_to_window(game->mlx, game->nums_png[0], pos_x, 0);
		return ;
	}
	while (movs > 0)
	{
		digit = movs % 10;
		mlx_image_to_window(game->mlx, game->images.wall, pos_x, 0);
		mlx_image_to_window(game->mlx, game->nums_png[digit], pos_x, 0);
		movs /= 10;
		pos_x -= 64;
	}
}

void	move_player(t_gamedata *game, int x, int y)
{
	int			new_x;
	int			new_y;
	static int	collects;
	static int	movs;

	new_x = game->player_x + x;
	new_y = game->player_y + y;
	if (game->map[new_y][new_x] != '1')
	{
		mlx_image_to_window(game->mlx, game->images.wall, 2 * 64, 0);
		mlx_image_to_window(game->mlx, game->images.wall, 64, 0);
		mlx_image_to_window(game->mlx, game->images.wall, 0, 0);
		movs++;
		put_nums(game, movs);
		put_before(game);
		collects = put_after(game, new_y, new_x, collects);
		if (collects == game->colls)
			game->exit = 1;
	}
}
