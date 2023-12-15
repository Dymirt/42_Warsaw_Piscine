/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:50:41 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/14 18:07:06 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	mini_atoi(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

void	set_header(int i, char *str)
{
	char	*header;

	header = malloc(i * sizeof(char));
	ft_strncpy(header, str, i);
	bsq_setup(header);
}

void	get_header(char *str)
{
	int			i;
	int			rows;
	int			cols;

	i = 0;
	rows = 0;
	cols = 0;
	while (str[i])
	{
		if (str[i] == '\n' && rows == 0)
			set_header(i, str);
		if (str[i] == '\n' && str[i - 1] != '\n')
		{
			if (rows == 0)
				cols = count_cols(&(str[i + 1]));
			if (str[i + cols + 1] != '\n')
				return ;
			allocate_string(cols, str, rows, i);
			rows++;
		}
		i++;
	}
}
