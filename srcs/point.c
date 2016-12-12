/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 00:03:24 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/12 16:14:14 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_trait(t_env *env, t_point ptA, t_point ptB)
{
	t_point ptC;
	
	mlx_pixel_put(env->mlx, env->win, ptA.x, ptA.y, 0x000000);
	mlx_pixel_put(env->mlx, env->win, ptB.x, ptB.y, 0x000000);
	if (ABS(ptA.x - ptB.x) < ABS(ptA.y - ptB.y))
	{
		ptC.x = 0;
		ptC.y = MIN(ptA.y, ptB.y);
		while (ptC.y <= MAX(ptB.y, ptA.y))
		{
			ptC.x = ptA.x + (double)((double)(ptB.x - ptA.x)*((double)(ptC.y - ptA.y)/(ptB.y - ptA.y)));
			mlx_pixel_put(env->mlx, env->win, ptC.x, ptC.y, 0x000000);
			ptC.y++;
		}	
	}
	else
	{
		ptC.y = 0;
		ptC.x = MIN(ptA.x, ptB.x);
		while (ptC.x <= MAX(ptB.x, ptA.x))
		{
			ptC.y = ptA.y + (double)((double)(ptB.y - ptA.y)*((double)(ptC.x - ptA.x)/(ptB.x - ptA.x)));
			mlx_pixel_put(env->mlx, env->win, ptC.x, ptC.y, 0x000000);
			ptC.x++;
		}
	}
}
