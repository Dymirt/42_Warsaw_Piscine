/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:18:37 by mwitasze          #+#    #+#             */
/*   Updated: 2023/12/04 00:23:08 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sky_scraper.h"

int		count_digits(char *str);
int		validate_input(char *str, int size);

void	remove_spaces(char *str);
void	create_puzzle(int dimensions, char *views);

int	main(int argc, char **argv)
{
	int	digits;

	if (argc == 2)
	{
		remove_spaces(argv[1]);
		digits = count_digits(argv[1]);
	}
	if (argc == 2 && digits % 4 == 0 && !validate_input(argv[1], (digits / 4)))
	{
		create_puzzle(digits / 4, argv[1]);
	}
	else
	{
		write(1, "Error: Input must be between 16 and 36. ", 41);
		write(1, "It has to be dividable by 4, without remainder.\n", 49);
		return (1);
	}
}

void	remove_spaces(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

int	count_digits(char *str)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			counter++;
		i++;
	}
	return (counter);
}

int	validate_input(char *str, int size)
{
	int	i;
	int	digit;

	i = 0;
	while (str[i] != '\0')
	{
		digit = str[i] - '0';
		if (digit < 1 || digit > size)
			return (1);
		i++;
	}
	return (0);
}
