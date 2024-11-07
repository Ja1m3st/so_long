/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:28:01 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/06 12:38:06 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	cont_row(char	**save)
{
	int	j;

	j = 0;
	while (save[j] != NULL)
		j++;
	return (j);
}

int	cont_colum(char **save)
{
	int	i;
	int	j;

	j = 0;
	while (save[j] != NULL)
	{
		i = 0;
		while (save[j][i] != '\0')
			i++;
		j++;
	}
	return (i);
}

int	ft_find_p(char **save, int *start_x, int *start_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (save[j] != 0)
	{
		while (save[j][i] != '\n' && save[j][i] != '\0')
		{
			if (save[j][i] == 'P')
			{
				*start_x = i;
				*start_y = j;
				return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	ft_backtrack_check(char **save, int j, int i)
{
	int	row;
	int	colum;

	row = cont_row(save);
	colum = cont_colum(save);
	if (j < 0 || i < 0
		|| save[j][i] == '1' || save[j][i] == 'X'
		|| save[j][i] == 'N')
		return (0);
	if (save[j][i] == 'E')
		return (1);
	save[j][i] = 'X';
	if (ft_backtrack_check(save, j + 1, i)
		|| ft_backtrack_check(save, j - 1, i)
		|| ft_backtrack_check(save, j, i + 1)
		|| ft_backtrack_check(save, j, i - 1))
		return (1);
	return (0);
}

int	ft_backtrack(char **save)
{
	int		start_x;
	int		start_y;
	int		row;
	int		colum;
	char	**tmp;

	tmp = ft_clone_save(save);
	row = cont_row(save);
	colum = cont_colum(save);
	if (!tmp)
		return (ft_free_tmp(tmp, row), 0);
	ft_find_p(tmp, &start_x, &start_y);
	if (!ft_backtrack_check(tmp, start_y, start_x))
		return (ft_free_tmp(tmp, row), 0);
	tmp[start_y][start_x] = 'P';
	ft_free_tmp(tmp, row);
	tmp = ft_clone_save(save);
	if (!ft_check_collectibles(tmp, ft_find_cs(save)))
		return (ft_free_tmp(tmp, row), 0);
	ft_free_tmp(tmp, row);
	return (1);
}
