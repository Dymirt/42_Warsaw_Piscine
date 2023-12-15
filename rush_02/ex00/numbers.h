/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:55:13 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/11 00:27:03 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct	s_numbers
{
	char	*ones[11];
	char	*teens[11];
	char	*tens[10];
	char	*multipl[10];
	int		multiplayers_size;
	char	*number;
};

typedef struct s_numbers	t_numbers ;

/*
char **ones = {"","Zero", "One", "Two", ... "Nine"};
char **teens = {"", "Eleven", "Twelve", ... "Hundred"};
char **tens = {"", "Ten", "Twenty", ... "Ninety"};
char **multiplayers = {"", "Thousand", "Million", "Billion" ...};
*/
