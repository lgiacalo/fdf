/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:42:12 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/14 23:26:08 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BIT_PER_PIXEL 32
# define ECT_PIX 30
# define ENDIAN 1
# define ECART_CASE (4 * ECT_PIX)
# define ISO 10
# define MIN(x, y) ((x < y) ? (x) : (y))
# define MAX(x, y) ((x < y) ? (y) : (x))

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
	char	*color;
}		t_point;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_point	len_win;
	void	*img;
	t_point	len_img;
	int		bit_per_pixel;
	int		img_ptr;
	int		endian;
	char	*str;
	int		len_str;
	t_point	**point;
	int		line;
	int		col;
	int		ecart_case;
	int		h_more;
}		t_env;

int		ft_read_file(char *tab, t_env *env);
void		ft_remplissage(t_env *env);
void		ft_trait(t_env *env, t_point a, t_point b, char *color);
t_point		ft_conv_point(t_env *env, int x, int y);

#endif
