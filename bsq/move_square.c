/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:57:11 by tszymans          #+#    #+#             */
/*   Updated: 2023/12/14 20:35:37 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function moves the square through an array.
// Returns 1 if finds valid position
// Returns 0 until position not valid or end of arr

#include "bsq.h"

t_bsq_map	move_square(t_bsq_map m)
{
	m.y1 = 0;
	while (m.y1 <= m.size_y - m.sq_size)
	{
		m.x1 = 0;
		while (m.x1 <= m.size_x - m.sq_size)
		{
			if (is_valid_square(m))
			{
				m.x_fin = m.x1;
				m.y_fin = m.y1;
				m.sq_size_fin = m.sq_size;
				return (m);
			}
			m.x1++;
		}
		m.y1++;
	}
	return (m);
}
