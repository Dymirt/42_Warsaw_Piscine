/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:03:08 by dkolida           #+#    #+#             */
/*   Updated: 2023/11/26 15:37:51 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (*str < 'A' || *str > 'z' || (*str < 'a' && *str > 'Z'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
