/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplissage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:27:34 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/19 03:01:19 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

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
		if (h > (MIN(x, (env->line - x)) * env->ect_pix / 3))
			if (env->h_more < (h - MIN(x, (env->line - x))
				* env->ect_pix / 3))
				env->h_more = h - MIN(x, (env->line - x))
				* env->ect_pix / 3;
	}
	env->h_more *= 3;
}

void		ft_remplissage(t_env *env)
{
	env->bit_per_pixel = BIT_PER_PIXEL;
	env->endian = ENDIAN;
	if (env->line < 100)
		env->ect_pix = 21;
	else if (env->line < 200)
		env->ect_pix = 6;
	else if (env->line < 300)
		env->ect_pix = 3;
	else
		env->ect_pix = 1;
	env->iso = (env->ect_pix / 3);
	env->ecart_case = env->ect_pix * 4;
	env->h_more = 0;
	ft_len_env(env);
	env->len_img.x = env->ect_pix + env->col + (env->col * env->ect_pix) +
		(env->line * env->iso) + (2 * env->h_more);
	env->len_img.y = (2 * env->h_more) + env->line +
		((env->line - 1) * env->ect_pix);
	env->len_win.x = env->len_img.x + 100;
	env->len_win.y = env->len_img.y + 100;
	env->img_ptr = env->len_img.x * 4;
	env->len_str = env->img_ptr * env->len_img.y;
}
