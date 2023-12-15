/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:54:55 by dkolida           #+#    #+#             */
/*   Updated: 2023/12/14 18:07:33 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_bsq_map
{
	int		size_x;
	int		size_y;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
	int		x1;
	int		y1;
	int		sq_size;
	int		x_fin;
	int		y_fin;
	int		sq_size_fin;
}	t_bsq_map;

//extern t_bsq_map	g_bsq_map;

typedef enum a_bool
{
	false = 0,
	true = 1
}	t_bool;

# define FALSE false
# define TRUE true

char		*ft_read(int file_descriptor);
int			ft_strlen(char *str);
char		*file_to_str(char *file_name);
char		*ft_strcat(char *dest, char *src);
char		*ft_read(int file_descriptor);
void		split_str(char *str);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
int			mini_atoi(char *str);
void		bsq_setup(char *header);
void		get_header(char *str);
int			is_valid_square(t_bsq_map m);
t_bsq_map	fill_square(t_bsq_map m);
t_bsq_map	move_square(t_bsq_map m);
int			bigger_square(t_bsq_map m);
void		engine(t_bsq_map g_bsq_map);
t_bool		validate_map(t_bsq_map m);
void		set_header(int i, char *str);
void		allocate_string(int cols, char *str, int rows, int i);
int			count_cols(char *str);

#endif
