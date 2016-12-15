/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplissage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:27:34 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/15 06:33:03 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

char		*ft_cpy_mod(char *src)
{
	char	dst[9];
	int	i;

	i = 0;
	dst[8] = '\0';
	while (src && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i > 0 && i < 8)
	{
		while (i < 8)
		{
			dst[i] = '0';
			i++;
		}
		return (ft_strdup(dst));
	}
	return (NULL);
}

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
//	env->ect_pix = env->line;
	env->ect_pix = ECT_PIX;
	env->ecart_case = env->ect_pix * 4;
	env->h_more = 0;
	ft_len_env(env);
	env->len_img.x = env->ect_pix + env->col + (env->col * env->ect_pix) +
		(env->line * ISO);
	env->len_img.y = (2 * env->h_more) + env->line +
		((env->line - 1) * env->ect_pix);
	env->len_win.x = env->len_img.x + 100;
	env->len_win.y = env->len_img.y + 100;
	env->img_ptr = env->len_img.x * 4;
	env->len_str = env->img_ptr * env->len_img.y;
}
