/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:52:00 by tszymans          #+#    #+#             */
/*   Updated: 2023/12/14 12:13:46 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	bigger_square(t_bsq_map m)
{
	if (m.sq_size + 1 <= m.size_x && m.sq_size + 1 <= m.size_y)
		return (1);
	else
		return (0);
}
