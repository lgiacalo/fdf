/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:21:10 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/05 18:48:01 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	my_key_funct(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	ft_putnbr(keycode);
	write(1, "\n", 1);
	return (0);
}

void	draw(void *mlx, void *win)
{
	int	x;
	int	y;

	printf("valeur mlx = %p\n", mlx);
	printf("valeur win = %p\n", win);
	x = 250;
	while (x < 350)
	{
		y = 250;
		while (y < 350)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
}

int	expose_hook(t_env *env)
{
	draw(env->mlx, env->win);
	return (0);
}


int	main(int ac, char **argv)
{
	t_env	first;
	int x, y;

	if ((first.mlx = mlx_init(0)) == NULL)
		return (EXIT_FAILURE);
	first.win = mlx_new_window(first.mlx, 600, 600, "First windows");

	printf("valeur mlx = %p\n", first.mlx);
	printf("valeur win = %p\n", first.win);
	mlx_expose_hook(first.win, expose_hook, &first);
	draw(first.mlx, first.win);

	mlx_key_hook(first.win, my_key_funct, 0);

	mlx_loop(first.mlx);
	return (0);
}
