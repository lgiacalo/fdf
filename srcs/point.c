/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 00:03:24 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/13 05:44:31 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_trait(t_env *env, t_point a, t_point b)
{
	t_point c;
	
	if (ABS(a.x - b.x) < ABS(a.y - b.y))
	{
		c.y = MIN(a.y, b.y) - 1;
		while (++c.y <= MAX(b.y, a.y))
		{
			c.x = a.x + ((b.x - a.x) * ((c.y - a.y)/(b.y - a.y)));
			mlx_pixel_put(env->mlx, env->win, c.x, c.y, 0x000000);
		}	
	}
	else
	{
		c.x = MIN(a.x, b.x) - 1;
		while (++c.x <= MAX(b.x, a.x))
		{
			c.y = a.y + ((b.y - a.y) * ((c.x - a.x)/(b.x - a.x)));
			mlx_pixel_put(env->mlx, env->win, c.x, c.y, 0x000000);
		}
	}
}

/*
** Fonction qui converti une case du tableau point, avec les bons indices
** par rapport a la taille de la fenetre.
** Parametre indices x et y de point[][] et retour X et Y.
*/

t_point	ft_conv_point(t_map *map, int x, int y)
{
	t_point point;

	point.x = x + ((x + 1) * ECT_PIX);
	point.y = y + map->h_more + (ECT_PIX * y);
	return (point);
}

int	ft_conv_ind(t_map *map, t_point a)
{
	int	ret;

	ret = 0;
	return (0);
}
