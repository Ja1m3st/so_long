/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack_c_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:38:56 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/06 12:37:22 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_find_cs(char **save)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (save[j] != 0)
	{
		while (save[j][i] != '\0')
		{
			if (save[j][i] == 'C')
				count++;
			i++;
		}
		i = 0;
		j++;
	}
	return (count);
}

char	*free_clone(char **clone, int j)
{
	int	k;

	k = 0;
	while (k < j)
		free(clone[k++]);
	free(clone);
	return (NULL);
}

char	**ft_clone_save(char **save)
{
	char	**clone;
	int		i;
	int		j;
	int		k;

	j = -1;
	k = 0;
	clone = malloc(sizeof(char *) * (cont_row(save) + 1));
	if (!clone)
		return (NULL);
	while (save[++j] != NULL)
	{
		clone[j] = malloc(sizeof(char) * (cont_colum(save) + 1));
		i = 0;
		if (!clone[j])
			free_clone(clone, j);
		while (save[j][i] != '\0')
		{
			clone[j][i] = save[j][i];
			i++;
		}
		clone[j][i] = '\0';
	}
	clone[j] = NULL;
	return (clone);
}

int	ft_backtrack_collectibles(char **save, int j, int i, int *found_count)
{
	int			row;
	int			colum;
	static int	red;

	row = cont_row(save);
	colum = cont_colum(save);
	if (j < 0 || i < 0
		|| save[j][i] == '1' || save[j][i] == 'X'
		|| save[j][i] == 'N')
		return (0);
	if (save[j][i] == 'C')
		red++;
	save[j][i] = 'X';
	ft_backtrack_collectibles(save, j + 1, i, found_count);
	ft_backtrack_collectibles(save, j - 1, i, found_count);
	ft_backtrack_collectibles(save, j, i + 1, found_count);
	ft_backtrack_collectibles(save, j, i - 1, found_count);
	return (red);
}

int	ft_check_collectibles(char **save, int cs)
{
	int	start_x;
	int	start_y;
	int	collectibles_count;
	int	found_count;

	collectibles_count = 0;
	found_count = 0;
	if (!ft_find_p(save, &start_x, &start_y))
		return (0);
	collectibles_count = ft_find_cs(save);
	if (ft_backtrack_collectibles(save, start_y, start_x, &found_count) == cs)
		return (1);
	return (0);
}
