/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:48:49 by dkolida           #+#    #+#             */
/*   Updated: 2023/11/23 12:30:48 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	write_combination(int i_0, int i_1, int j_0, int j_1);
void	write_separator(void);

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			if (i != j)
			{
				write_combination(i / 10, i % 10, j / 10, j % 10);
				if (i < 98 && j <= 99)
				{
					write_separator();
				}
			}
			j++;
		}
		i++;
	}
}

void	write_combination(int i_0, int i_1, int j_0, int j_1)
{
	char	combination[5];

	combination[0] = i_0 + '0';
	combination[1] = i_1 + '0';
	combination[2] = ' ';
	combination[3] = j_0 + '0';
	combination[4] = j_1 + '0';
	write(1, &combination, 5);
}

void	write_separator(void)
{
	char	saparator[2];

	saparator[0] = ',';
	saparator[1] = ' ';
	write(1, &saparator, 2);
}
