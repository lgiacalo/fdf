/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 20:06:03 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/01/12 06:11:54 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		ft_display_color(char *chaine, char *color)
{
	char	*tronc;
	int		len;
	int		i;

	i = -1;
	if ((tronc = ft_strchr(chaine, 44)))
	{
		tronc++;
		len = ft_strlen(tronc);
		while (++i < len)
			color[i] = tronc[i];
	}
	if (i > 1)
	{
		i--;
		while (++i < 8)
			color[i] = '0';
	}
	else
	{
		ft_memset((void *)color, 70, sizeof(char) * 8);
		color[0] = '0';
		color[1] = 'x';
	}
	color[8] = '\0';
}

static void	ft_h_more(t_env *env)
{
	int	x;
	int	y;
	int	h;

	y = -1;
	h = 0;
	while (++y < env->len_map.y)
	{
		x = -1;
		h = 0;
		while (++x < env->len_map.x)
			if (h < ABS(env->map[y][x].z))
				h = ABS(env->map[y][x].z);
		if ((h > (y * 10)) || (h > ((env->len_map.y - y - 1) * 10)))
		{
			h = h - MIN((y * 10), ((env->len_map.y - y - 1) * 10));
			if ((h % 10) == 0)
				h = h / 10;
			else
				h = (h / 10) + 1;
			if (env->h_more < h)
				env->h_more = h;
		}
	}
	env->h_more = env->h_more * (env->ect_pix + 1);
}

void		ft_remplissage(t_env *env)
{
	env->bit_per_pixel = BIT_PER_PIXEL;
	env->endian = ENDIAN;
	if (env->len_map.y < 100)
		env->ect_pix = 10;
	else if (env->len_map.y < 200)
		env->ect_pix = 3;
	else if (env->len_map.y < 300)
		env->ect_pix = 1;
	else
		env->ect_pix = 0;
	if (env->ect_pix == 0)
		env->iso = 1;
	else
		env->iso = env->ect_pix;
	env->h_more = 0;
	ft_h_more(env);
	env->len_img.x = 2 * (env->ect_pix + env->len_map.x + (env->len_map.x *
			env->ect_pix) + (4 * env->h_more) + (env->len_map.y * env->iso));
	env->len_img.y = 2 * (env->len_map.y + ((env->len_map.y - 1) * env->ect_pix)
		+ (4 * env->h_more));
	env->img_ptr = env->len_img.x * 4;
	env->len_str = env->img_ptr * env->len_img.y;
}
