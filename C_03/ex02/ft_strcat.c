/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:45:14 by dkolida           #+#    #+#             */
/*   Updated: 2023/11/28 14:23:19 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	while (*src != '\0')
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
//*
int main(void)
{
	char dest[10] = "Hello ";
	char dest_1[10] = "Hello ";	
	char src[7] = "world!";
	char src_1[7] = "world!";

	printf("%s\n", ft_strcat(dest, src));
	printf("%s\n", strcat(dest_1, src_1));
}
//*/