/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 00:03:24 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/14 21:26:18 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	ft_trait(t_env *env, t_point a, t_point b)
{
	t_point	c;

	if (ABS(a.x - b.x) < ABS(a.y - b.y))
	{
		c.y = MIN(a.y, b.y) - 1;
		while (++c.y <= MAX(b.y, a.y))
		{
			c.x = (int)(a.x + ((b.x - a.x) * ((c.y - a.y) / (b.y - a.y))));
			ft_conv_ind(env, c);
		}
	}
	else
	{
		c.x = MIN(a.x, b.x) - 1;
		while (++c.x <= MAX(b.x, a.x))
		{
			c.y = (int)(a.y + ((b.y - a.y) * ((c.x - a.x) / (b.x - a.x))));
			ft_conv_ind(env, c);
		}
	}
}

t_point	ft_conv_point(t_env *env, int x, int y)
{
	t_point point;

	point.x = x + ((x + 1) * ECT_PIX) + (ISO * (env->line - y));
	point.y = y + env->h_more + (ECT_PIX * y);
	if (env->point[y][x].z != 0)
	{
		point.x = (int)(point.x - 1.5 * env->point[y][x].z);
		point.y = (int)(point.y - (2.1) * env->point[y][x].z);
	}
	env->point[y][x].x = point.x;
	env->point[y][x].y = point.y;
	return (point);
}

int		ft_conv_ind(t_env *env, t_point a)
{
	int	ret;

	ret = (a.x * 4 + (a.y * env->img_ptr));
	ft_color_pixel(env, ret);
	return (0);
}

void	ft_color_pixel(t_env *env, int ret)
{
	env->str[ret] = 250;
	env->str[ret + 1] = 250;
	env->str[ret + 2] = 250;
}

void	ft_grillage(t_env *env)
{
	int	x;
	int	y;

	y = -1;
	while (++y < env->line)
	{
		x = -1;
		while (++x < env->col - 1)
			ft_trait(env, ft_conv_point(env, x, y),
					ft_conv_point(env, (x + 1), y));
	}
	y = -1;
	while (++y < env->line - 1)
	{
		x = -1;
		while (++x < env->col)
			ft_trait(env, ft_conv_point(env, x, y),
					ft_conv_point(env, x, (y + 1)));
	}
}
