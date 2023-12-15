/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:58:33 by dkolida           #+#    #+#             */
/*   Updated: 2023/11/28 15:23:44 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (*to_find != '\0')
	{
		while (*str != '\0')
		{
			i = 0;
			if (*str == to_find[i])
			{
				while (str[i] == to_find[i])
				{
					if (to_find[i + 1] == '\0')
						return (str);
					i++;
				}
			}
			str++;
		}
		return (0);
	}
	return (str);
}

/*
int main(void)
{
	char str[8] = "Hello";
	char str_1[8] = "Hello";
	char to_find[4] = "1";

	printf("%s\n", strstr(str_1, to_find));
	printf("%s\n", ft_strstr(str, to_find));
}
//*/
