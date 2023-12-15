/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:26:54 by dkolida           #+#    #+#             */
/*   Updated: 2023/11/28 17:05:50 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_lenth;
	unsigned int	src_lenth;
	unsigned int	i;

	dest_lenth = 0;
	src_lenth = 0;
	while (dest[dest_lenth] != '\0')
		dest_lenth++;
	while (src[src_lenth] != '\0')
		src_lenth++;
	i = dest_lenth;
	if (size == 0 || size <= dest_lenth)
		return (src_lenth + size);
	while (i < size - 1 && *src != '\0')
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest_lenth + src_lenth);
}

//*
int main (void)
{
	char dest[12] = "Hello ";
	char dest_1[10] = "Hello ";	
	
	char src[7] = "world!";
	char src_1[7] = "";

	printf("%d\n", ft_strlcat(dest, src, 12));
	printf("%s\n", dest);
	printf("%d\n", ft_strlcat(dest_1, src_1, 6));
	printf("%s\n", dest_1);
	
}
//*/