/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:43:36 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/01/12 06:12:38 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_color(char one, char two)
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

void	ft_color_pixel(t_env *env, int ret, char *color)
{
	env->str[ret] = ft_color(color[2], color[3]);
	env->str[ret + 1] = ft_color(color[4], color[5]);
	env->str[ret + 2] = ft_color(color[6], color[7]);
}
