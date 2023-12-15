/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:09:53 by olhoncha          #+#    #+#             */
/*   Updated: 2023/12/10 23:45:56 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);

char	*file_to_str(char *file_name)
{
	int		file_descriptor;
	int		bytes_read;
	char	*text;
	char	*tmp;
	char	buffer[2];

	text = malloc(sizeof(char));
	file_descriptor = open(file_name, O_RDONLY);
	bytes_read = 1;
	if (file_descriptor == -1)
	{
		write(1, "Can not open the file", 21);
		return ("");
	}
	while (bytes_read != 0)
	{
		bytes_read = read(file_descriptor, buffer, 1);
		tmp = malloc((ft_strlen(text) + 2) * sizeof(char));
		ft_strcat(tmp, text);
		buffer[1] = '\0';
		ft_strcat(tmp, buffer);
		text = tmp;
	}
	close(file_descriptor);
	return (text);
}
/*#include <stdio.h>

int	main()
{
	char	file_name[20] = "numbers.dict";

	printf("%s", file_to_str(file_name));
	return (0);
}*/
