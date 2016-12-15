/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:42:12 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/15 06:33:01 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BIT_PER_PIXEL 32
# define ECT_PIX 10
# define ENDIAN 1
# define ISO (ECT_PIX / 3)
# define MIN(x, y) ((x < y) ? (x) : (y))
# define MAX(x, y) ((x < y) ? (y) : (x))

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	char		*color;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_point		len_win;
	void		*img;
	t_point		len_img;
	int			bit_per_pixel;
	int			img_ptr;
	int			endian;
	char		*str;
	int			len_str;
	t_point		**point;
	int			line;
	int			col;
	int			ect_pix;
	int			ecart_case;
	int			h_more;
}				t_env;

int				ft_read_file(char *tab, t_env *env);
void			ft_remplissage(t_env *env);
void			ft_trait(t_env *env, t_point a, t_point b, char *color);
t_point			ft_conv_point(t_env *env, int x, int y);
char			*ft_cpy_mod(char *src);

#endif
