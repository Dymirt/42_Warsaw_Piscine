/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:21:31 by dkolida           #+#    #+#             */
/*   Updated: 2023/11/23 11:42:46 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	write_combination(int first, int second, int third);
void	write_separator(void);

void	ft_print_comb(void)
{
	int	i;
	int	first;
	int	second;
	int	third;

	i = 0;
	while (i <= 789)
	{	
		first = i / 100;
		second = i / 10 % 10;
		third = i % 10;
		if (first < second && second < third)
		{	
			write_combination(first, second, third);
			if (i < 789)
			{
				write_separator();
			}
		}
		i++;
	}
}

void	write_combination(int first, int second, int third)
{
	char	output[3];

	output[0] = first + '0';
	output[1] = second + '0';
	output[2] = third + '0';
	write(1, &output, 3);
}

void	write_separator(void)
{
	char	saparator[2];

	saparator[0] = ',';
	saparator[1] = ' ';
	write(1, &saparator, 2);
}
