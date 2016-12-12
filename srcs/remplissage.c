/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplissage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:27:34 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/12 13:29:40 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_len_map(t_env *env, t_map *map)
{
	int	x;
	int	y;
	int	h;

	x = -1;
	h = 0;
	while (++x < map->line)
	{
		y = -1;
		h = 0;
		while (++y < map->col)
			if (ABS(h) < ABS(map->point[x][y]))
				h = ABS(map->point[x][y]);
		if (h > (MIN(x, (map->line - x)) * ECT_PIX / 3))
			if (map->h_more < (h - MIN(x, (map->line - x))
				* ECT_PIX / 3))
				map->h_more = h - MIN(x, (map->line - x))
				* ECT_PIX / 3;
	}
}

void		ft_remplissage(t_env *env, t_map *map)
{
	env->bit_per_pixel = BIT_PER_PIXEL;
	env->endian = ENDIAN;
	env->img_ptr = map->col * (ECART_CASE + 4) + ECART_CASE;
	
	map->ecart_case = ECART_CASE;
	map->h_more = 0;
	ft_len_map(env, map);
	env->len_str = (2 * (map->h_more*env->img_ptr) +
	(env->img_ptr *(map->line + ((map->line - 1) * ECT_PIX))));
	env->len_img.x = ECT_PIX + map->col + (map->col * ECT_PIX);
	env->len_img.y = (2 * map->h_more) + map->line +
	((map->line - 1) * ECT_PIX);
	env->len_win.x = env->len_img.x + 100;
	env->len_win.y = env->len_img.y + 100;

}
