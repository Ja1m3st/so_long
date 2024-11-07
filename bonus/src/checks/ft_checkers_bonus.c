/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:17:46 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/04 16:17:08 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_ep(char **save)
{
	int	i;
	int	j;
	int	e;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	e = 0;
	while (save[j] != 0)
	{
		while (save[j][i] != '\0')
		{
			if (save[j][i] == 'E')
				e++;
			else if (save[j][i] == 'P')
				p++;
			i++;
		}
		i = 0;
		j++;
	}
	if (e != 1 || p != 1)
		return (0);
	return (1);
}

int	ft_check_c(char **save)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (save[j] != 0)
	{
		while (save[j][i] != '\0')
		{
			if (save[j][i] == 'C')
				c++;
			i++;
		}
		i = 0;
		j++;
	}
	if (c < 1)
		return (0);
	return (1);
}

int	ft_check_form(char **save, int row)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (save[j] != 0)
	{
		while (save[j][i] != '\0')
			i++;
		if (i != row)
			return (0);
		i = 0;
		j++;
	}
	return (1);
}

int	ft_check_walls_one(char **save, int row, int colum)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < row)
	{
		if (save[j][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (j < colum)
	{
		if (save[j][i] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	ft_check_walls_last(char **save, int row, int colum)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < colum)
	{
		if (save[j][row - 1] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (i < row)
	{
		if (save[colum -1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
