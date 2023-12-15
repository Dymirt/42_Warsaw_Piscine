/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:51:33 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/13 19:48:14 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*file_to_str(char *file_name)
{
	int		file_descriptor;
	char	*text;
	char	**file;

	text = malloc(sizeof(char));
	text[0] = '\0';
	file = &text;
	file_descriptor = open(file_name, O_RDONLY);
	if (file_descriptor == -1)
	{
		write(1, "Error: Can't open the file: ", 29);
		write(1, file_name, ft_strlen(file_name));
		write(1, "\n", 1);
		return (text);
	}
	free(text);
	*file = ft_read(file_descriptor);
	close(file_descriptor);
	return (*file);
}

char	*ft_read(int file_descriptor)
{
	char	buffer[2];
	char	*tmp;
	char	*text;

	text = malloc(sizeof(char));
	text[0] = '\0';
	buffer[1] = '\0';
	while (read(file_descriptor, buffer, 1))
	{
		tmp = malloc((ft_strlen(text) + 2) * sizeof(char));
		ft_strcat(tmp, text);
		ft_strcat(tmp, buffer);
		text = tmp;
	}
	return (text);
}
