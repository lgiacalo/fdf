/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplissage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:27:34 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/14 22:23:01 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_len_env(t_env *env)
{
	int	x;
	int	y;
	int	h;

	x = -1;
	h = 0;
	while (++x < env->line)
	{
		y = -1;
		h = 0;
		while (++y < env->col)
			if (ABS(h) < ABS(env->point[x][y].z))
				h = ABS(env->point[x][y].z);
		if (h > (MIN(x, (env->line - x)) * ECT_PIX / 3))
			if (env->h_more < (h - MIN(x, (env->line - x))
				* ECT_PIX / 3))
				env->h_more = h - MIN(x, (env->line - x))
				* ECT_PIX / 3;
	}
	env->h_more *= 3;
}

void		ft_remplissage(t_env *env)
{
	env->bit_per_pixel = BIT_PER_PIXEL;
	env->endian = ENDIAN;
	env->ecart_case = ECART_CASE;
	env->h_more = 0;
	ft_len_env(env);
	env->len_img.x = ECT_PIX + env->col + (env->col * ECT_PIX) +
		(env->line * ISO);
	env->len_img.y = (2 * env->h_more) + env->line +
		((env->line - 1) * ECT_PIX);
	env->len_win.x = env->len_img.x + 100;
	env->len_win.y = env->len_img.y + 100;
	env->img_ptr = env->len_img.x * 4;
	env->len_str = env->img_ptr * env->len_img.y;
}
