/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olhoncha <olhoncha@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:30:07 by olhoncha          #+#    #+#             */
/*   Updated: 2023/12/10 23:46:08 by olhoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*file_to_str(char *file_name);
int		ft_strlen(char *str);

int	count_lines(char *str)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			line++;
		i++;
	}
	return (line);
	return (0);
}

void	**memory(int line, char *str, char **by_lines)
{
	int	i;

	i = 0;
	while (i < line)
	{
		by_lines[i] = malloc((ft_strlen(str) + 1) * sizeof(char));
		i++;
	}
	return (0);
}

char	**str_line(char *str)
{
	int		i;
	int		j;
	int		line;
	char	**by_lines;

	i = 0;
	line = count_lines(str);
	by_lines = (char **)malloc((line) * sizeof(char *));
	memory(line, str, by_lines);
	while (i < line)
	{
		j = 0;
		while (*str != '\n' && *str != '\0')
		{
			by_lines[i][j] = *str;
			str++;
			j++;
		}
		by_lines[i][j] = '\0';
		str++;
		i++;
	}
	return (by_lines);
}
/*#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	write(1, str, i);
}

int	main()
{
	char src[] = "kjfhkjshfka\nskfjjfw\nkwejfiw\n\n";

	char **out = str_line(src);
	ft_putstr(out[0]);
	ft_putstr(out[1]);
	ft_putstr(out[2]);
	ft_putstr(out[3]);
	return (0);
}*/
