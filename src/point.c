/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 22:57:21 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/01/12 06:12:49 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	ft_conv_point(t_env *env, int x, int y)
{
	t_point point;

	point.x = 2 * (x + ((x + 1) * env->ect_pix) + (2 * env->h_more)
		+ (env->iso * (env->len_map.y - y)));
	point.y = 2 * (y + (2 * env->h_more) + (env->ect_pix * y));
	if (env->map[y][x].z != 0)
	{
		point.x = (int)(point.x - 1.0 * env->map[y][x].z);
		point.y = (int)(point.y - (1.5) * env->map[y][x].z);
	}
	return (point);
}

void	ft_conv_ind(t_env *env, t_point a, char *color)
{
	int	ret;

	ret = (a.x * 4 + (a.y * env->img_ptr));
	if (ret >= env->len_str || ret < 0)
		return ;
	ft_color_pixel(env, ret, color);
}

void	ft_trait(t_env *env, t_point a, t_point b, char *color)
{
	t_point	c;

	if (ABS(a.x - b.x) < ABS(a.y - b.y))
	{
		c.y = MIN(a.y, b.y) - 1;
		while (++c.y <= MAX(b.y, a.y))
		{
			c.x = (int)(a.x + ((double)(b.x - a.x) * (double)
						((double)(c.y - a.y) / (double)(b.y - a.y))));
			ft_conv_ind(env, c, color);
		}
	}
	else
	{
		c.x = MIN(a.x, b.x) - 1;
		while (++c.x <= MAX(b.x, a.x))
		{
			c.y = (int)(a.y + ((double)(b.y - a.y) * (double)
						((double)(c.x - a.x) / (double)(b.x - a.x))));
			ft_conv_ind(env, c, color);
		}
	}
}

void	ft_grid_line(t_env *env)
{
	int		x;
	int		y;

	y = -1;
	while (++y < env->len_map.y)
	{
		x = -1;
		while (++x < env->len_map.x - 1)
		{
			ft_trait(env, ft_conv_point(env, x, y),
					ft_conv_point(env, (x + 1), y), env->map[y][x].color);
		}
	}
}

void	ft_grid_col(t_env *env)
{
	int		x;
	int		y;

	y = -1;
	while (++y < env->len_map.y - 1)
	{
		x = -1;
		while (++x < env->len_map.x)
		{
			ft_trait(env, ft_conv_point(env, x, y),
					ft_conv_point(env, x, (y + 1)), env->map[y][x].color);
		}
	}
}
