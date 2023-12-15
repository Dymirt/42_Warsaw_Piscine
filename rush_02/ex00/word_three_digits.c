/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_three_digits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:00:57 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/10 22:22:46 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"
#include <unistd.h>
#include <stdio.h>

void	convert_three_digits(int num, t_numbers numb);
void	print_hundreds(int dig_3, t_numbers numb);
int		ft_strlen(char *str);

void	convert_three_digits(int num, t_numbers numb)
{
	int	dig_1;
	int	dig_2;
	int	dig_3;

	dig_1 = num % 10;
	dig_2 = (num / 10) % 10;
	dig_3 = (num / 100) % 10;
	print_hundreds(dig_3, numb);
	if (dig_2 == 1)
	{
		write(1, numb.teens[dig_1], ft_strlen(numb.teens[dig_1]));
	}
	else
	{
		if (dig_2 > 0)
			write(1, numb.tens[dig_2 - 1], ft_strlen(numb.tens[dig_2 - 1]));
		if (dig_1 > 0)
			write(1, numb.ones[dig_1 + 1], ft_strlen(numb.ones[dig_1 + 1]));
	}
}

void	print_hundreds(int dig_3, t_numbers numb)
{
	if (dig_3 > 0)
	{
		write(1, numb.ones[dig_3 + 1], ft_strlen(numb.ones[dig_3 + 1]));
		write(1, numb.tens[9], ft_strlen(numb.tens[9]));
	}
}
