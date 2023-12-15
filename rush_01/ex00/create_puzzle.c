/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_puzzle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:06:56 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/04 00:22:40 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sky_scraper.h"

void	create_puzzle(int dimensions, char *views);
int		**allocate_array(int dimensions);
void	fill_array(int **grid, int dimensions, char *str);
int		solve_sky_scraper(t_skyskraper SkySkraperBoard);
void	print_grid(t_skyskraper SkySkraperBoard);
void	put_int(int i);

struct s_SkySkraper	g_board;

void	create_puzzle(int dimensions, char *views)
{
	int	i;
	int	**grid;
	int	**clue;

	grid = allocate_array(dimensions);
	clue = allocate_array(dimensions);
	fill_array(clue, dimensions, views);
	g_board.dimensions = dimensions;
	g_board.grid = grid;
	g_board.views = clue;
	solve_sky_scraper(g_board);
	print_grid(g_board);
	i = 0;
	while (i < dimensions)
	{
		free(grid[i]);
		free(clue[i]);
		i++;
	}
	free(grid);
	free(clue);
}

int	**allocate_array(int dimensions)
{
	int	**array;
	int	i;

	array = (int **)malloc(dimensions * sizeof(int *));
	i = 0;
	while (i < dimensions)
	{
		array[i] = (int *)malloc(dimensions * sizeof(int));
		i++;
	}
	return (array);
}

void	print_grid(t_skyskraper SkySkraperBoard)
{
	int	i;
	int	j;

	i = 0;
	while (i < SkySkraperBoard.dimensions)
	{
		j = 0;
		while (j < SkySkraperBoard.dimensions)
		{
			if (SkySkraperBoard.grid[i][j] == 0)
			{
				write(1, "Error\n", 7);
				return ;
			}
			put_int(SkySkraperBoard.grid[i][j]);
			if (j < SkySkraperBoard.dimensions - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	put_int(int i)
{
	char	n;

	n = i + '0';
	write(1, &n, 1);
}

void	fill_array(int **grid, int dimensions, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < dimensions)
	{
		j = 0;
		while (j < dimensions)
		{
			grid[i][j] = str[k] - '0';
			j++;
			k++;
		}
		i++;
	}
}
