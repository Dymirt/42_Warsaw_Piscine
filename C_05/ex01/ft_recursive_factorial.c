/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:40:29 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/06 16:17:58 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb);

int	ft_recursive_factorial(int nb)
{
	unsigned int	factorial;

	factorial = 1;
	if (nb >= 0)
	{
		if (nb > 1)
		{
			factorial *= nb * ft_recursive_factorial(nb - 1);
		}
		return (factorial);
	}
	else
	{
		return (0);
	}
}
