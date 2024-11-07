/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:36:11 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/07 14:03:18 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_ber(char	*str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str) - 4;
	while (str[j] != 0)
	{
		if (str[j] == 'r' || str[j] == 'e' || str[j] == 'b'
			|| str[j] == '.')
			j++;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*line;
	char	**save;
	int		colum;

	if (argc < 2 || argc > 2)
		return (ft_printf("Error\n"));
	if (!ft_check_ber(argv[1]))
		return (ft_printf("Error\n"));
	line = ft_read_ber(argv[1]);
	if (!line)
		return (0);
	colum = ft_read_colum(line);
	save = ft_split(line, '\n');
	if (!save)
		return (free(line), 0);
	if (!ft_checkers(save, cont_colum(save), cont_row(save))
		|| (cont_row(save) != ft_read_colum(line)))
	{
		ft_free_tmp(save, colum);
		return (free(line), ft_printf("Error\n"));
	}
	main_mlx(save);
	free(line);
	ft_free_tmp(save, colum);
	return (0);
}
