/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:50:30 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/07 19:43:50 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power);

int	ft_iterative_power(int nb, int power)
{
	unsigned int	result;

	if (nb == 0 && power == 0)
	{
		return (1);
	}
	else if (power < 0)
	{
		return (0);
	}
	result = 1;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}

/*
#include <stdio.h>

int main (void)
{
	printf("%d\n", ft_iterative_power(-2, 3));
	printf("%d\n", ft_iterative_power(-1729, 0));
	printf("%d\n", ft_iterative_power(-2285, 2));
	printf("%d\n", ft_iterative_power(2, 2));
	printf("%d\n", ft_iterative_power(3, 4));
	printf("%d\n", ft_iterative_power(5, 5));
	printf("%d\n", ft_iterative_power(-1, 10));
}
//*/
