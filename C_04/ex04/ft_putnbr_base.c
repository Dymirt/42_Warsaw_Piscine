/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:37:23 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/04 18:52:36 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	is_invalid_base(char *base, int base_lenth)
{
	int	i;
	int	j;

	i = 0;
	if (base_lenth < 2)
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr_base_recursive(int nbr, char *base, int base_length)
{
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base_recursive(-(nbr / base_length), base, base_length);
		write(1, &base[-(nbr % base_length)], 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base_length)
	{
		ft_putnbr_base_recursive(nbr / base_length, base, base_length);
	}
	write(1, &base[nbr % base_length], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_length;

	base_length = ft_strlen(base);
	if (is_invalid_base(base, base_length))
	{
		return ;
	}
	ft_putnbr_base_recursive(nbr, base, base_length);
}
/*
int main() {
    // Examples of using the ft_putnbr_base function
    ft_putnbr_base(-2147483648, "0123456789");  // Decimal
    write(1,"\n", 1);
		ft_putnbr_base(2147483647, "0123456789");  // Decimal
    write(1,"\n", 1);

   ft_putnbr_base(-2147483648, "01");  // Binary
 	write(1,"\n", 1);

    ft_putnbr_base(-2147483648, "0123456789ABCDEF");  // Hexadecimal
 	write(1,"\n", 1);

    ft_putnbr_base(-2147483648, "poneyvif");  // Octal
 	write(1,"\n", 1);

	    // Examples of using the ft_putnbr_base function
    ft_putnbr_base(20, "0123456789");  // Decimal
    write(1,"\n", 1);
		ft_putnbr_base(-2, "0123456789");  // Decimal
    write(1,"\n", 1);


   ft_putnbr_base(-2, "01");  // Binary
 	write(1,"\n", 1);

    ft_putnbr_base(-2, "0123456789ABCDEF");  // Hexadecimal
 	write(1,"\n", 1);

    ft_putnbr_base(-2, "poneyvif");  // Octal
 	write(1,"\n", 1);

    // Invalid cases
    ft_putnbr_base(123, "");      // Invalid base
 	write(1,"\n", 1);

    ft_putnbr_base(123, "11");    // Invalid base
 	write(1,"\n", 1);

    ft_putnbr_base(123, "a+");    // Invalid base
 	write(1,"\n", 1);

    return 0;
}
//*/
