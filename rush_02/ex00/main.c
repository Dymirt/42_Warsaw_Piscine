/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:45:24 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/11 00:27:19 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "numbers.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
void	numbers_to_words(t_numbers numbers);
int		checkint(char *str);
char	*file_to_str(char *file_name);
void	fill_structure(t_numbers numbers, char *filename);

struct s_numbers	g_numbers;

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!checkint(argv[1]))
			return (1);
		g_numbers.number = argv[1];
		fill_structure(g_numbers, "numbers.dict");
	}
	else if (argc == 3)
	{
		if (!checkint(argv[2]))
			return (1);
		fill_structure(g_numbers, argv[1]);
		g_numbers.number = argv[2];
	}
	else
	{
		write(1, "Usage: <numb> or <name.dict> <num>\n", 36);
		return (1);
	}
	numbers_to_words(g_numbers);
	write(1, "\n", 1);
	return (0);
}

int	checkint(char *str)
{
	int	result;
	int	leadingzero;

	result = 0;
	leadingzero = 1;
	while (*str == ' ')
		str++;
	if (*str == '+' || (*str == '-' && str++))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		if (*str != '0' || !leadingzero)
		{
			result = result * 10 + (*str++ - '0');
			leadingzero = 0;
		}
		else
			str++;
	}
	while (*str == ' ')
		str++;
	if (*str == '\0')
		return (result);
	else
		return (0);
}

/*
	t_numbers	numbers = {
		.ones = {"", "Zero", "One", "Two", "Three", "Four",
		 "Five", "Six", "Seven", "Eight", "Nine"},
		.teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
		 "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"},
		.tens = {"", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
		 "Seventy", "Eighty", "Ninety", "Hundred"},
		.multipl = {"", "Thousand", "Million", "Billion"},
		.number = number,
	};
*/
