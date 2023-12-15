/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:58:21 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/11 00:34:56 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"
#include <stdlib.h>

char	*file_to_str(char *file_name);
char	**str_line(char *str);

void	fill_structure(t_numbers numbers, char *filename)
{
	char	*str;
	char	**lines;

	str = file_to_str(filename);
	lines = str_line(str);
	numbers = numbers;
	free(str);
	free(lines);
}

// TODO Fill numbers
