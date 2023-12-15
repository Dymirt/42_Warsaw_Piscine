/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:08:11 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/06 16:17:16 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	unsigned int	factorial;

	factorial = 1;
	if (nb >= 0)
	{
		while (nb)
		{
			factorial *= nb;
			nb--;
		}
		return (factorial);
	}
	else
	{
		return (0);
	}
}
