/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:42:12 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/08 05:19:32 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BIT_PER_PIXEL 32
# define ECART_NBR_PIXEL 25
# define ENDIAN 1
# define ECART_PT (4 * ECART_NBR_PIXEL)
# define MIN(x, y) ((x < y) ? (x) : (y))
# define MAX(x, y) ((x < y) ? (y) : (x))

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_map
{
	char		**point;
	int			line;
	int			col;
	int			ecart_pt; // = 25 pixels
}				t_map;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bit_per_pixel; // = 32 en bits = 4 octets
	int			img_ptr; // en octet = 4 * (ECART_PT + NBR_COL) + ECART_PT
	int			endian;
	char		*chaine;
	int			len_chaine; // = 4 * nbrLigne * nbrColonne
}				t_env;

#endif
