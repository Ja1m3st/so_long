/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers_two_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:29:35 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/04 16:18:54 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_all(char **save)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (save[j] != NULL )
	{
		while (save[j][i] != '\0')
		{
			if (save[j][i] != '1' && save[j][i] != '0'
				&& save[j][i] != 'C' && save[j][i] != 'E'
				&& save[j][i] != 'P' && save[j][i] != 'N')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	ft_checkers(char **save, int row, int colum)
{
	if (!ft_check_ep(save))
		return (0);
	if (!ft_check_c(save))
		return (0);
	if (!ft_check_all(save))
		return (0);
	if (!ft_check_form(save, row))
		return (0);
	if (!ft_check_walls_one(save, row, colum))
		return (0);
	if (!ft_check_walls_last(save, row, colum))
		return (0);
	if (!ft_backtrack(save))
		return (0);
	return (1);
}
