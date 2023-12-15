/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:36:13 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/04 18:53:24 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str);

int	get_sign(char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			count *= -1;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = get_sign(str, &i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}

/*
int main(void)
{
	printf("%d\n", ft_atoi(" ---+--214758364b567"));
	printf("%d\n", ft_atoi(" ---+--2147483648ab567"));
	printf("%d\n", ft_atoi(" ---+---214748f3648ab567"));

	printf("%d\n", ft_atoi(" ---+--214748-3648ab567"));

	printf("%d\n", ft_atoi(" ---+---2-14748-3648ab567"));

	printf("%d\n", ft_atoi(" ---+-0-3648ab567"));
	printf("%d\n", ft_atoi(" - +--+---214748-3648ab567"));
	printf("%d\n", ft_atoi("  - +--+---214748-3648ab567"));
	printf("%d\n", ft_atoi("--580764829"));

	printf("%d\n", ft_atoi("  ---+--+01234506789ab567"));
	printf("%d\n", ft_atoi("  ---+--+01234506789ab567"));


}
//*/
