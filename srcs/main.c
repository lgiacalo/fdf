/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:21:10 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/12 00:33:38 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
#include <string.h>

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

	x = 0;
	while (x < 400)
	{
		y = 0;
		while (y < 400)
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

int	main(int argc, char **argv)
{
	t_env	*a;
	t_map	*b;
	int		x, y, ret;

	a = (t_env*)malloc(sizeof(t_env) * 1);
	b = (t_map*)malloc(sizeof(t_map) * 1);

	ret = ft_read_file(argv[1], a, b);
	if (ret == -1)
		return (-1);

	if (!(a->mlx = mlx_init(0)))
		return (EXIT_FAILURE);
	if (!(a->img = mlx_new_image(a->mlx, a->len_img.x, a->len_img.y)))
		return (EXIT_FAILURE);
	if (!(a->str = mlx_get_data_addr(a->img, &(a->bit_per_pixel), &(a->img_ptr), &(a->endian))))
		return (EXIT_FAILURE);
	if (!(a->win = mlx_new_window(a->mlx, a->len_win.x, a->len_win.y, "FDF")))
		return (EXIT_FAILURE);

	x = 0;
	draw(a->mlx, a->win);
	while (x < a->len_str)
	{
		if ((x + 1) % 4 == 0)
			x++;
		a->str[x] = 250;
		x++;
	}
	x = 460;
	while (x < 560)
	{
		if ((x + 1) % 4 == 0)
			x++;
		a->str[x] = 0;
		x++;
	}
	x = 460 + 2 * a->img_ptr;
	while (x < (580 + 2 * a->img_ptr))
	{
		if ((x + 1) % 4 == 0)
			x++;
		a->str[x] = 0;
		x++;
	}


	mlx_put_image_to_window(a->mlx, a->win, a->img, 50, 50);

	t_point ptA;
	t_point ptB;
	t_point ptC;

	ptA.x = 185;
	ptA.y = 65;
	ptB.x = 1;
	ptB.y = 2;


	mlx_pixel_put(a->mlx, a->win, ptA.x, ptA.y, 0x000000);
	mlx_pixel_put(a->mlx, a->win, ptB.x, ptB.y, 0x000000);

	if (ABS(ptA.x - ptB.x) < ABS(ptA.y - ptB.y))
	{
		ptC.x = 0;
		ptC.y = MIN(ptA.y, ptB.y);
		while (ptC.y <= MAX(ptB.y, ptA.y))
		{
			ptC.x = ptA.x + (double)((double)(ptB.x - ptA.x)*((double)(ptC.y - ptA.y)/(ptB.y - ptA.y)));
			mlx_pixel_put(a->mlx, a->win, ptC.x, ptC.y, 0x000000);
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
			mlx_pixel_put(a->mlx, a->win, ptC.x, ptC.y, 0x000000);
			ptC.x++;
		}
	}
/*
	printf("valeur win = %p\n", a->win);
	mlx_expose_hook(a->win, expose_hook, &a);
	draw(a->mlx, a->win);
*/
	mlx_key_hook(a->win, my_key_funct, 0);

	mlx_loop(a->mlx);
	return (0);
}
