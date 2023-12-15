/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:17:19 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/07 13:26:09 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);

int	ft_sqrt(int nb)
{
	double	sqrt;
	double	temp;
	int		result;

	if (nb > 3)
	{
		sqrt = nb / 2;
		temp = 0;
		while (sqrt != temp)
		{
			temp = sqrt;
			sqrt = (nb / temp + temp) / 2;
		}
		result = sqrt;
	}
	if (nb == 1)
		return (nb);
	else if (result * result == nb)
		return (sqrt);
	else
		return (0);
}

/*
#include <stdio.h>

int main (void)
{
	printf("ft_sqrt\n");
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(-2));
	printf("%d\n", ft_sqrt(3));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(5));
	printf("%d\n", ft_sqrt(35));
}
//*/
