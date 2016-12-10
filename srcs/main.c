/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:21:10 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/10 22:38:45 by lgiacalo         ###   ########.fr       */
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

	printf("VALEUR DE IMG_PTR : %d\n", a->img_ptr);
	printf("VALEUR DE ECART_CASE : %d\n", b->ecart_case);

	x = 0;
	y = 0;
	while (x < b->line)
	{
		y = 0;
		while (y < b->col)
		{
			printf("%d.", b->point[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}


	a->img_ptr = 2400; // 4*nbr colonne
	a->len_chaine = 1440000;

	if ((a->mlx = mlx_init(0)) == NULL)
		return (EXIT_FAILURE);
	if ((a->img = mlx_new_image(a->mlx, 600, 600)) == NULL)
		return (EXIT_FAILURE);
	if ((a->chaine = mlx_get_data_addr(a->img, &(a->bit_per_pixel), &(a->img_ptr), &(a->endian))) == NULL)
		return (EXIT_FAILURE);
	write(1, "5merde\n", 7);


	x = 0;
	printf("valeur en int de la couleur rouge : %d\n", mlx_get_color_value(a->mlx, 0xFF0000));
	printf("valeur en int de la couleur blanc : %d\n", mlx_get_color_value(a->mlx, 0xFFFFFF));
	printf("valeur en int de la couleur bleu : %d\n", mlx_get_color_value(a->mlx, 0x0000FF));
	a->win = mlx_new_window(a->mlx, 800, 800, "MECHANT !!!!");
	draw(a->mlx, a->win);
	printf("ecart entre les points en octet : %d\n", ECART_CASE);
	while (x < a->len_chaine)
	{
		if ((x + 1) % 4 == 0)
			x++;
		a->chaine[x] = 250;
		x++;
	}
	x = 460;
	while (x < 560)
	{
		if ((x + 1) % 4 == 0)
			x++;
		a->chaine[x] = 0;
		x++;
	}
	x = 460 + 2 * a->img_ptr;
	while (x < (580 + 2 * a->img_ptr))
	{
		if ((x + 1) % 4 == 0)
			x++;
		a->chaine[x] = 0;
		x++;
	}


	mlx_put_image_to_window(a->mlx, a->win, a->img, 100, 100);

	printf("valeur chaine = %p\n", a->chaine);

	t_point ptA;
	t_point ptB;
	t_point ptC;

	ptA.x = 185;
	ptA.y = 65;
	ptB.x = 1;
	ptB.y = 2;


	mlx_pixel_put(a->mlx, a->win, ptA.x, ptA.y, 0x000000);
	mlx_pixel_put(a->mlx, a->win, ptB.x, ptB.y, 0x000000);

	printf("valeur point A avant condition swap : (%d,%d)\n", ptA.x, ptA.y);
	printf("valeur point B avant condition swap: (%d,%d)\n", ptB.x, ptB.y);
	
	if (ABS(ptA.x - ptB.x) < ABS(ptA.y - ptB.y))
	{
		ptC.x = 0;
		ptC.y = MIN(ptA.y, ptB.y);
		while (ptC.y <= MAX(ptB.y, ptA.y))
		{
//			printf("valeur point C dans le while : (%d,%d)\n", ptC.x, ptC.y);
			ptC.x = ptA.x + (double)((double)(ptB.x - ptA.x)*((double)(ptC.y - ptA.y)/(ptB.y - ptA.y)));
			mlx_pixel_put(a->mlx, a->win, ptC.x, ptC.y, 0x000000);
			ptC.y++;
		}	
		printf("je suis passee par le swap !!\nDonc un pixel par ligne\n");
	}
	else
	{
		ptC.y = 0;
		ptC.x = MIN(ptA.x, ptB.x);
		while (ptC.x <= MAX(ptB.x, ptA.x))
		{
//			printf("valeur point C dans le while : (%d,%d)\n", ptC.x, ptC.y);
			ptC.y = ptA.y + (double)((double)(ptB.y - ptA.y)*((double)(ptC.x - ptA.x)/(ptB.x - ptA.x)));
			mlx_pixel_put(a->mlx, a->win, ptC.x, ptC.y, 0x000000);
			ptC.x++;
		}
		printf("pas de swap !!\nDonc un pixel par colonne\n");
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
