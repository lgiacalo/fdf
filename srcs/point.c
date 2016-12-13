/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 00:03:24 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/13 17:16:08 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_trait(t_map *map, t_env *env, t_point a, t_point b)
{
	t_point c;
	
	if (ABS(a.x - b.x) < ABS(a.y - b.y))
	{
		c.y = MIN(a.y, b.y) - 1;
		while (++c.y <= MAX(b.y, a.y))
		{
			c.x = a.x + ((b.x - a.x) * ((c.y - a.y)/(b.y - a.y)));
			ft_conv_ind(map, env, c);
		}	
	}
	else
	{
		c.x = MIN(a.x, b.x) - 1;
		while (++c.x <= MAX(b.x, a.x))
		{
			c.y = a.y + ((b.y - a.y) * ((c.x - a.x)/(b.x - a.x)));
			ft_conv_ind(map, env, c);
		}
	}
}

/*
** Fonction qui converti une case du tableau point, avec les bons indices
** par rapport a la taille de la fenetre.
** Parametre indices x et y de point[][] et retour X et Y.
*/

t_point	ft_conv_point(t_map *map, t_env *env, int x, int y)
{
	t_point point;

	point.x = x + ((x + 1) * ECT_PIX);
	point.y = y + map->h_more + (ECT_PIX * y);
	return (point);
}

int	ft_conv_ind(t_map *map, t_env *env, t_point a)
{
	int	ret;

	ret = (a.x * 4 + (a.y * env->img_ptr));
	ft_color_pixel(map, env, ret);
	return (0);
}

void	ft_color_pixel(t_map *map, t_env *env, int ret)
{
	env->str[ret] = 0;
	env->str[ret + 1] = 0;
	env->str[ret + 2] = 0;
}

void	ft_grillage(t_map *map, t_env *env)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->line)
	{
		x = -1;
		while (++x < map->col - 1)
			ft_trait(map, env, ft_conv_point(map, env, x, y), ft_conv_point(map, env, (x + 1), y));
	}
	y = -1;
	while (++y < map->line - 1)
	{
		x = -1;
		while (++x < map->col)
			ft_trait(map, env, ft_conv_point(map, env, x, y), ft_conv_point(map, env, x, y + 1));
	}
}
