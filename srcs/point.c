/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 00:03:24 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/15 19:54:54 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point			ft_conv_point(t_env *env, int x, int y)
{
	t_point point;

	point.x = x + ((x + 1) * env->ect_pix) + (ISO * (env->line - y)) + (env->h_more / 2);
	point.y = y + env->h_more + (env->ect_pix * y);
	if (env->point[y][x].z != 0)
	{
		point.x = (int)(point.x - 1.5 * env->point[y][x].z);
		point.y = (int)(point.y - (2.1) * env->point[y][x].z);
	}
	env->point[y][x].x = point.x;
	env->point[y][x].y = point.y;
	return (point);
}

static int		ft_color(char one, char two)
{
	int x;
	int y;
	int	ret;

	ft_toupper(one);
	ft_toupper(two);
	if (ft_isdigit(one))
		x = one - '0';
	else
		x = one - 'A' + 10;
	if (ft_isdigit(two))
		y = two - '0';
	else
		y = two - 'A' + 10;
	ret = x * 16 + y;
	return (ret);
}

static void		ft_color_pixel(t_env *env, int ret, char *color)
{
	if (color)
	{
		env->str[ret] = ft_color(color[6], color[7]);
		env->str[ret + 1] = ft_color(color[5], color[4]);
		env->str[ret + 2] = ft_color(color[3], color[2]);
	}
	else
	{
		env->str[ret] = 255;
		env->str[ret + 1] = 255;
		env->str[ret + 2] = 255;
	}
}

static int		ft_conv_ind(t_env *env, t_point a, char *color)
{
	int	ret;

	ret = (a.x * 4 + (a.y * env->img_ptr));
	ft_color_pixel(env, ret, color);
	return (0);
}

void			ft_trait(t_env *env, t_point a, t_point b, char *color)
{
	t_point	c;

	if (ABS(a.x - b.x) < ABS(a.y - b.y))
	{
		c.y = MIN(a.y, b.y) - 1;
		while (++c.y <= MAX(b.y, a.y))
		{
			c.x = (int)(a.x + ((b.x - a.x) * ((c.y - a.y) / (b.y - a.y))));
			ft_conv_ind(env, c, color);
		}
	}
	else
	{
		c.x = MIN(a.x, b.x) - 1;
		while (++c.x <= MAX(b.x, a.x))
		{
			c.y = (int)(a.y + ((b.y - a.y) * ((c.x - a.x) / (b.x - a.x))));
			ft_conv_ind(env, c, color);
		}
	}
}
