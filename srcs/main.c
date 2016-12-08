/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:21:10 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/08 02:21:59 by lgiacalo         ###   ########.fr       */
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

int	ft_read_file(char *tab, t_env *env, t_map map)
{

	return (0);
}



int	main(int argc, char **argv)
{
	t_env	*a;
	t_map	*b;
	int		x, ret;

	a = (t_env*)malloc(sizeof(t_env) * 1);
	b = (t_map*)malloc(sizeof(t_map) * 1);

	//ret = ft_read_file(argv[1], a, b);

	a->bit_per_pixel = BIT_PER_PIXEL;
	a->img_ptr = 2400; // 4*nbr colonne
	a->endian = ENDIAN;
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
	printf("ecart entre les points en octet : %d\n", ECART_PT);
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

	mlx_put_image_to_window(a->mlx, a->win, a->img, 100, 100);

	printf("valeur chaine = %p\n", a->chaine);

	t_point ptA;
	t_point ptB;
	t_point ptC;

	double	m, p;

	ptA.x = 2;
	ptA.y = 1;
	ptB.x = 65;
	ptB.y = 185;


	mlx_pixel_put(a->mlx, a->win, ptA.x, ptA.y, 0x000000);
	mlx_pixel_put(a->mlx, a->win, ptB.x, ptB.y, 0x000000);

	if (ABS(ptA.x - ptB.x) < ABS(ptA.y - ptB.y))
	{
		ft_swap(&(ptA.x), &(ptB.x));
		ft_swap(&(ptA.y), &(ptB.y));
		printf("je suis passee par le swap !!\nDonc un pixel par ligne\n");
	}
	else
		printf("pas de swap !!\nDonc un pixel par colonne\n");

	printf("valeur point A : (%d,%d)\n", ptA.x, ptA.y);
	printf("valeur point B : (%d,%d)\n", ptB.x, ptB.y);

	// http://raphaello.univ-fcomte.fr/IG/Algorithme/Algorithmique.htm 
		
	ptC.x = ptB.x;
	ptC.y = 0;
	
	printf("valeur point C : (%d,%d)\n", ptC.x, ptC.y);
	
	m = (double)((ptB.y - ptA.y) / (ptB.x - ptA.x));
	p = ptA.y - (m * ptA.x);

	while (ptC.x <= ptA.x)
	{
		printf("valeur point C dans le while : (%d,%d)\n", ptC.x, ptC.y);
		ptC.y = (int)(m * ptC.x + p);
		mlx_pixel_put(a->mlx, a->win, ptC.x, (ptC.y + 1), 0x000000);
		mlx_pixel_put(a->mlx, a->win, (ptC.x + 1), ptC.y, 0x000000);
		mlx_pixel_put(a->mlx, a->win, ptC.x, ptC.y, 0x000000);
		mlx_pixel_put(a->mlx, a->win, (ptC.x + 1), (ptC.y + 1), 0x000000);
		ptC.x++;
	}



/*	printf("valeur win = %p\n", a->win);
	mlx_expose_hook(a->win, expose_hook, &a);
	draw(a->mlx, a->win);
*/
	mlx_key_hook(a->win, my_key_funct, 0);

	mlx_loop(a->mlx);
	return (0);
}
