/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:15:36 by tszymans          #+#    #+#             */
/*   Updated: 2023/12/14 12:31:14 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function checks if the square is valid i.e.
* it should not contain any obstacles.
* If it IS VALID (no obstacles) it should return (1)
* If it is NOT VALID (the obstacle is within the square) it should return (0)
*
* The square is defined by coordinates of the upper left corner,
* its size and definition of the obstacle. Any other sign is treated as valid.
*
* VALID squre 3x3			NOT VALID square 3x3
*	...							..o		...
*	...							...		...
*	...							...		o..
*/

#include "bsq.h"

int	is_valid_square(t_bsq_map m)
{
	int		x;
	int		y;

	x = 0;
	while (x < m.sq_size)
	{
		y = 0;
		while (y < m.sq_size)
		{
			if (m.map[m.y1 + y][m.x1 + x] == m.obstacle)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
