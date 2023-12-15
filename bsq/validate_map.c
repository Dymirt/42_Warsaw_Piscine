/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:16:40 by tszymans          #+#    #+#             */
/*   Updated: 2023/12/14 18:09:02 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_bool	validate_map(t_bsq_map m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m.size_x)
	{
		j = 0;
		while (j < m.size_y)
		{
			if (m.map[i][j] != m.empty && m.map[i][j] != m.obstacle)
			{
				write(1, "map error\n", 11);
				return (FALSE);
			}
			j++;
		}
		i++;
	}
	if (j != m.size_y)
	{
		write(1, "map error\n", 11);
		return (FALSE);
	}
	return (TRUE);
}
