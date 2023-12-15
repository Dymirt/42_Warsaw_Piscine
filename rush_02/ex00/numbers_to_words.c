/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_to_words.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:26:09 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/10 23:12:55 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"
#include <unistd.h>

void	convert_three_digits(int num, t_numbers numb);
int		ft_strlen(char *str);
int		mini_atoi(char *str);
void	print_core(int *start_index, int i, t_numbers numbers);
int		print_three_digits(int l, int *start_i, t_numbers numb);
void	print_overflov(int *start_i, int *i, t_numbers numbers);

void	numbers_to_words(t_numbers numbers)
{
	int		i;
	int		start_i;

	if (numbers.number[0] == '0')
	{
		write(1, numbers.ones[1], ft_strlen(numbers.ones[1]));
		return ;
	}
	start_i = 0;
	i = ((ft_strlen(numbers.number) - (ft_strlen(numbers.number) % 3)) / 3);
	print_overflov(&start_i, &i, numbers);
	print_core(&start_i, i, numbers);
	if (start_i + 1 < ft_strlen(numbers.number))
		print_three_digits(3, &start_i, numbers);
}

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

void	print_core(int *start_index, int i, t_numbers numbers)
{
	int	atoi_number;

	while (i > 0)
	{
		atoi_number = print_three_digits(3, start_index, numbers);
		if (atoi_number != 0)
		{
			write(1, numbers.multipl[i], ft_strlen(numbers.multipl[i]));
		}
		i--;
	}
}

int	print_three_digits(int l, int *start_i, t_numbers numbers)
{
	int		j;
	char	three_digits[4];
	int		atoi_number;

	j = 0;
	while (j < l)
	{
		three_digits[j] = numbers.number[*start_i];
		*start_i = *start_i + 1;
		j++;
	}
	if (l < 3)
		three_digits[2] = '\0';
	three_digits[3] = '\0';
	atoi_number = mini_atoi(three_digits);
	convert_three_digits(atoi_number, numbers);
	return (atoi_number);
}

void	print_overflov(int *start_i, int *i, t_numbers numbers)
{
	if (ft_strlen(numbers.number) % 3 != 0)
	{
		print_three_digits((ft_strlen(numbers.number) % 3), start_i, numbers);
		if (*i > 0)
		{
			write(1, numbers.multipl[*i], ft_strlen(numbers.multipl[*i]));
			*i = *i - 1;
		}
		if (*start_i + 1 == ft_strlen(numbers.number))
			return ;
	}
	else
		*i = *i - 1;
}
