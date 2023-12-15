/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:26:06 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/07 20:33:55 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb);
int	my_sqrt(int nb);

int	ft_is_prime(int nb)
{
	int	nb_sqrt;

	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0 || nb < 2)
		return (0);
	nb_sqrt = my_sqrt(nb);
	if ((nb_sqrt * nb_sqrt) == nb)
		return (0);
	while (nb_sqrt > 3)
	{
		if (nb % nb_sqrt == 0)
			return (0);
		nb_sqrt--;
	}
	return (1);
}

int	my_sqrt(int nb)
{
	double	sqrt;
	double	temp;

	sqrt = nb / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (nb / temp + temp) / 2;
	}
	return (sqrt);
}

/*
#include <stdio.h>

int main (void)
{
	printf("%d",ft_is_prime(0));
	printf("%d",ft_is_prime(1));
	printf("%d",ft_is_prime(2));
	printf("%d",ft_is_prime(1223));
}
//*/
