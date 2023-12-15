/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_scraper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:41:32 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/03 20:14:33 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_SkySkraper
{
	int	**grid;
	int	**views;
	int	dimensions;
};
typedef struct s_SkySkraper	t_skyskraper;
