/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 21:21:45 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/14 20:46:12 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bsq.h"

struct s_bsq_map	g_bsq_map;

int	main(int argc, char **argv)
{
	char	buffer[256];
	size_t	bytes_read;
	int		i;

	bytes_read = 0;
	if (argc == 1)
	{
		while (!bytes_read)
		{
			bytes_read = read(0, buffer, sizeof(buffer) - 1);
			get_header(file_to_str(buffer));
			write(1, "\n", 1);
			if (validate_map(g_bsq_map))
				engine(g_bsq_map);
		}
	}
	i = 1;
	while (i < argc)
	{
		get_header(file_to_str(argv[i]));
		if (validate_map(g_bsq_map))
			engine(g_bsq_map);
		i++;
	}
}

void	engine(t_bsq_map g_bm)
{
	int	i;

	g_bm.sq_size = 1;
	g_bm.x1 = 0;
	g_bm.y1 = 0;
	g_bm.x_fin = 0;
	g_bm.y_fin = 0;
	while (g_bm.sq_size <= g_bm.size_x && g_bm.sq_size <= g_bm.size_y)
	{
		g_bm = move_square(g_bm);
		g_bm.sq_size++;
	}
	i = 0;
	g_bm = fill_square(g_bm);
	while (i < g_bm.size_y)
	{
		//printf("%s\n", g_bm.map[i]);
		write(1, g_bm.map[i], ft_strlen(g_bm.map[i]));
		write(1, "\n", 1);
		i++;
	}
}

void	allocate_string(int cols, char *str, int rows, int i)
{
	char		*tmp;

	tmp = malloc((cols + 1) * sizeof(char));
	ft_strncpy(tmp, &str[i + 1], cols);
	g_bsq_map.map[rows] = tmp;
}

int	count_cols(char *str)
{
	int	cols;

	cols = 0;
	while (*str != '\n')
	{
		cols++;
		str++;
	}
	g_bsq_map.size_x = cols;
	return (cols);
}

void	bsq_setup(char *header)
{
	char	*size;
	int		len_header;

	len_header = ft_strlen(header);
	size = malloc((len_header - 3) * sizeof(char));
	ft_strncpy(size, header, len_header - 3);
	g_bsq_map.size_y = mini_atoi(size);
	g_bsq_map.empty = header[len_header -3];
	g_bsq_map.obstacle = header[len_header - 2];
	g_bsq_map.full = header[len_header - 1];
	g_bsq_map.map = malloc((g_bsq_map.size_y) * sizeof(char *));
	free(header);
}
