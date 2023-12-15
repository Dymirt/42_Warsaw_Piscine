/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:20:47 by tszymans          #+#    #+#             */
/*   Updated: 2023/12/14 12:12:03 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	This function fills the biggest square of coordinates x, y and size sq_size
//	with fill character

#include "bsq.h"

t_bsq_map	fill_square(t_bsq_map m)
{
	int	x;
	int	y;

	x = 0;
	while (x < m.sq_size_fin)
	{
		y = 0;
		while (y < m.sq_size_fin)
		{
			m.map[m.y_fin + y][m.x_fin + x] = m.full;
			y++;
		}
		x++;
	}
	return (m);
}
