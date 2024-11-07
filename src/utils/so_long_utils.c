/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:25:40 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/07 13:54:55 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_save(char **save)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (save[j] != NULL)
	{
		i = 0;
		while (save[j][i] != '\0')
		{
			ft_printf("\033[1;32m""%c""\033[0m", save[j][i]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
}

int	ft_read_row(char	*line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	i++;
	return (i);
}

int	ft_read_colum(char	*line)
{
	int	i;
	int	row;

	i = 0;
	row = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			row++;
		}
		i++;
	}
	row++;
	return (row);
}

char	*ft_read_ber(char *ber)
{
	int		fd;
	char	*buffer;
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	fd = open(ber, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer != NULL)
	{
		if (fd == -1)
		{
			free(str);
			free(buffer);
			close(fd);
			return (NULL);
		}
		str = ft_strjoin_get(str, buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	free(buffer);
	return (str);
}

void	ft_free_tmp(char **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
