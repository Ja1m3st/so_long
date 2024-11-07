/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:28:08 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/06 12:53:12 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include "MLX42/MLX42.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct mlx_texture_t
{
	mlx_texture_t	*floor;
	mlx_texture_t	*pj;
	mlx_texture_t	*wall;
	mlx_texture_t	*heart;
	mlx_texture_t	*exit;
}	t_textures;

typedef struct mlx_image_t
{
	mlx_image_t	*floor;
	mlx_image_t	*pj;
	mlx_image_t	*wall;
	mlx_image_t	*heart;
	mlx_image_t	*exit;
}	t_images;

typedef struct t_gamedata
{
	int			player_x;
	int			player_y;
	mlx_t		*mlx;
	char		**map;
	t_images	images;
	int			colls;
	int			exit;
}	t_gamedata;

int		main(int argc, char **argv);
char	*ft_read_ber(char *ber);
int		ft_read_colum(char	*line);
int		ft_read_row(char	*line);
void	ft_print_save(char **save);
int		ft_checkers(char **save, int row, int colum);
int		ft_check_walls_last(char **save, int row, int colum);
int		ft_check_walls_one(char **save, int row, int colum);
int		ft_check_form(char **save, int row);
int		ft_check_c(char **save);
int		ft_check_ep(char **save);
int		ft_check_all(char **save);
int		ft_backtrack(char **save);
int		ft_find_p(char **save, int *start_x, int *start_y);
int		ft_backtrack_check(char **save, int j, int i);
int		cont_colum(char **save);
int		cont_row(char	**save);
int		ft_find_cs(char **save);
int		ft_check_collectibles(char **save, int cs);
int		ft_backtrack_collectibles(char **save, int j, int i, int *found_count);
char	**ft_clone_save(char **save);
void	ft_free_tmp(char **matrix, int rows);
int64_t	main_mlx(char **map);
void	ft_error(void);
mlx_t	*initialize_window(int width, int height);
void	load_textures(t_textures *textures);
void	textures_to_images(mlx_t *mlx, t_textures *textures, t_images *images);
void	data_game(t_gamedata *game, char **map, mlx_t *mlx, t_images images);
void	render_map(mlx_t *mlx, char **map, t_images *images);
void	data_game(t_gamedata *game, char **map, mlx_t *mlx, t_images images);
void	put_before(t_gamedata *game);
int		put_after(t_gamedata *game, int new_y, int new_x, int collects);
void	move_player(t_gamedata *game, int x, int y);
void	key_press(mlx_key_data_t keydata, void *param);

#endif