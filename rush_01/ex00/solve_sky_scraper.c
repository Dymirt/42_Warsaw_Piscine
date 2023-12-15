/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sky_scraper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:06:52 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/03 20:59:00 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky_scraper.h"

int	solve_sky_scraper(t_skyskraper SkySkraperBoard);
int	try_numbers(t_skyskraper SkySkraperBoard, int row, int col);
int	is_valid(t_skyskraper SkySkraperBoard, int row, int col, int num);
int	check_views(t_skyskraper SkySkraperBoard);

int	solve_sky_scraper(t_skyskraper SkySkraperBoard)
{
	int	row;
	int	col;

	row = 0;
	while (row < SkySkraperBoard.dimensions)
	{
		col = 0;
		while (col < SkySkraperBoard.dimensions)
		{
			if (SkySkraperBoard.grid[row][col] == 0)
			{
				if (!try_numbers(SkySkraperBoard, row, col))
					return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

int	try_numbers(t_skyskraper SkySkraperBoard, int row, int col)
{
	int	num;

	num = 1;
	while (num <= SkySkraperBoard.dimensions)
	{
		if (is_valid(SkySkraperBoard, row, col, num))
		{
			SkySkraperBoard.grid[row][col] = num;
			if (solve_sky_scraper(SkySkraperBoard))
			{
				if (check_views(SkySkraperBoard))
					return (1);
				else
					SkySkraperBoard.grid[row][col] = 0;
			}
			else
			{
				SkySkraperBoard.grid[row][col] = 0;
			}
		}
		num++;
	}
	return (0);
}

int	is_valid(t_skyskraper SkySkraperBoard, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < SkySkraperBoard.dimensions)
	{
		if (SkySkraperBoard.grid[row][i] == num)
			return (0);
		i++;
	}
	i = 0;
	while (i < SkySkraperBoard.dimensions)
	{
		if (SkySkraperBoard.grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}
