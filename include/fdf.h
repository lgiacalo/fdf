/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:42:12 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/01/12 05:09:02 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BIT_PER_PIXEL 32
# define ENDIAN 1
# define MIN(x, y) (((x) < (y)) ? (x) : (y))
# define MAX(x, y) (((x) < (y)) ? (y) : (x))

# include "../minilibx_macos/mlx.h"
# include "../libft/include/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_map
{
	int			z;
	char		color[9];
}				t_map;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	t_point		len_img;
	int			bit_per_pixel;
	int			img_ptr;
	char		*str;
	int			len_str;
	t_map		**map;
	t_point		len_map;
	int			ect_pix;
	int			endian;
	int			h_more;
	int			iso;
	double		pos_x;
	double		pos_y;
}				t_env;

void			ft_exit_fdf(void);
void			ft_malloc_error(void);
void			ft_read_error(void);
void			ft_bad_file(void);
int				ft_nbr_lines(char *str);
int				ft_strlen_double(char **str);
void			ft_display_lines(t_env *env, char **chaine, int y);
void			ft_display_file(t_env *env, char *str);
void			ft_display_color(char *chaine, char *color);
void			ft_remplissage(t_env *env);
void			ft_grid_line(t_env *env);
void			ft_grid_col(t_env *env);
void			ft_trait(t_env *env, t_point a, t_point b, char *color);
void			ft_conv_ind(t_env *env, t_point a, char *color);
t_point			ft_conv_point(t_env *env, int x, int y);
int				ft_color(char one, char two);
void			ft_color_pixel(t_env *env, int ret, char *color);

#endif
