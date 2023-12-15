/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:15:57 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/04 20:35:59 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_array_of_strings(char **array, int size);

int		ft_strcmp(char *s1, char *s2);

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_sort_array_of_strings(argv, argc);
	while (i < argc)
	{
		while (*argv[i])
		{
			write(1, argv[i], 1);
			argv[i]++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_sort_array_of_strings(char **array, int size)
{
	int	loop_counter;
	int	i;

	loop_counter = 0;
	while (loop_counter < size)
	{
		i = 1;
		while (i < size - 1)
		{
			if (ft_strcmp(array[i], array[i + 1]) > 0)
			{
				array[0] = array[i];
				array[i] = array[i + 1];
				array[i + 1] = array[0];
			}
			i++;
		}
		loop_counter++;
	}
}
