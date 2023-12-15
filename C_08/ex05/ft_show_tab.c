/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:03:23 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/14 11:55:30 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void				ft_show_tab(struct s_stock_str *par);
void				ft_putnbr(int nb);

void	ft_show_tab(struct s_stock_str *par)
{
	int	index;

	index = 0;
	while (par[index].str)
	{
		write(1, par[index].str, par[index].size);
		write (1, "\n", 1);
		ft_putnbr(par[index].size);
		write (1, "\n", 1);
		write(1, par[index].copy, par[index].size);
		write (1, "\n", 1);
		index++;
	}
}

void	ft_putnbr(int nb)
{
	char	n;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	n = nb % 10 + '0';
	write (1, &n, 1);
}

/*
int	main(int argc, char **argv)
{

	typedef struct	s_stock_str
	{
		int		size;
		char	*str;
		char	*copy;
	}	t_stock_str;

	struct s_stock_str	*structs;

	structs = ft_strs_to_tab(argc, argv);

	ft_show_tab(structs);
}
*/
