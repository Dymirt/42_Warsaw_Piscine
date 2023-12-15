/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sky_scraper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:47:33 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/03 21:53:07 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sky_scraper.h"

int	check_views(t_skyskraper SkySkraperBoard);
int	check_view(int *array, t_skyskraper SkySkraperBoard, int clue);
int	*get_col(t_skyskraper SkySkraperBoard, int col);
int	*rev(int *array, int length);

int	check_views(t_skyskraper Board)
{
	int	i;
	int	d;

	d = Board.dimensions;
	i = 0;
	while (i < d)
	{
		if (!check_view(Board.grid[i], Board, Board.views[2][i]))
			return (0);
		if (!check_view(rev(Board.grid[i], d), Board, Board.views[3][i]))
			return (0);
		if (!check_view(get_col(Board, i), Board, Board.views[0][i]))
			return (0);
		if (!check_view(rev(get_col(Board, i), d), Board, Board.views[1][i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_view(int *array, t_skyskraper SkySkraperBoard, int clue)
{
	int	max_height;
	int	visible_skyscrapers;
	int	i;

	max_height = 0;
	visible_skyscrapers = 0;
	i = 0;
	while (i < SkySkraperBoard.dimensions)
	{
		if (array[i] > max_height)
		{
			visible_skyscrapers++;
			max_height = array[i];
		}
		i++;
	}
	return (visible_skyscrapers == clue);
}

int	*get_col(t_skyskraper SkySkraperBoard, int col)
{
	int	*column;
	int	i;

	column = malloc(SkySkraperBoard.dimensions * sizeof(int));
	i = 0;
	while (i < SkySkraperBoard.dimensions)
	{
		column[i] = SkySkraperBoard.grid[i][col];
		i++;
	}
	return (column);
}

int	*rev(int *array, int length)
{
	int	*reversed;
	int	i;

	reversed = malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		reversed[i] = array[length - i - 1];
		i++;
	}
	return (reversed);
}
