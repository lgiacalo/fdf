/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:42:12 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/10 22:38:49 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BIT_PER_PIXEL 32
# define ECART_NBR_PIXEL 30
# define ENDIAN 1
# define ECART_CASE (4 * ECART_NBR_PIXEL)
# define MIN(x, y) ((x < y) ? (x) : (y))
# define MAX(x, y) ((x < y) ? (y) : (x))

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_map
{
//	char		**point;
	int		**point;
	int			line;
	int			col;
	int			ecart_case;
}				t_map;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bit_per_pixel;
	int			img_ptr; // en octet = 4 * (ECART_PT + NBR_COL) + ECART_PT
	int			endian;
	char		*chaine;
	int			len_chaine; // = 4 * nbrLigne * nbrColonne
}				t_env;

int			ft_read_file(char *tab, t_env *env, t_map *map);

#endif
