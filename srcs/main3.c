/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:21:10 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/09 02:45:08 by lgiacalo         ###   ########.fr       */
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

int	ft_display_file(t_list *list, t_map *map)
{
	t_list	*temp1;
	t_list	*temp2;
	int		i;
	char	**mop;

	printf("adresse list : %p\n", list);
	printf("adresse list-content : %p\n", list->content);
	list = temp1;
	ft_putstr((char*)(list->content));
	write(1, "\n", 1);
	printf("longeur list = nbr de ligne : %d\n", map->line);
	if ((mop = (char**)malloc(sizeof(char*) * (map->line + 1))) == NULL)
		return (-1);
	write(1, "555\n", 4);
	mop[map->line] = 0;
	write(1, "555\n", 4);
	i = 0;
	while (temp1)
	{
		printf("ligne %d : %s\n", i, (char*)((list)->content));
		printf("valeur pointeur next : %p\n", temp1->next);
		mop[i] = ft_strdup((char*)(temp1->content));
		write(1, "grrr\n", 5);
		i++;
		temp2 = temp1;
		temp1 = temp1->next;
	//	free(temp2);
	}
	printf("valeur de i : %d\n", i);
	return (0);
	write(1, "666\n", 4);
	map->col = ft_strlen(mop[0]);
	write(1, "777\n", 4);
	ft_print_words_tables(mop);
	write(1, "888\n", 4);

	return (0);
}



int	ft_read_file(char *tab, t_env *env, t_map *map)
{
	int		fd;
	int		len;
	t_list	*debut;
	t_list	*list;
	char	*temp;

	if ((fd = open(tab, O_RDONLY)) == -1)
			return (-1);
	write(1, "111\n", 4);
	while (get_next_line(fd, &temp) == 1)
	{
		printf("buff : %s\t len : %zu\n", temp, ft_strlen(temp));
		len = ft_strlen(temp);
		list = ft_lstnew((void const*)temp, ((size_t)len + 1));
		printf("valeur : %s\n", (char*)(list->content));
		ft_lstadd_end(&debut, list);
	}
	list = debut;
	map->line = (int)ft_lstsize(list);
	printf("longeur list = nbr de ligne : %d\n", map->line);
	printf("premiere ligne : %s\n", (char*)(debut->content));
	printf("seconde ligne : %s\n", (char*)(debut->next)->content);
	printf("troisieme ligne : %s\n", (char*)((debut->next)->next)->content);
	write(1, "222\n", 4);
	printf("adresse list : %p\n", debut);
	printf("adresse list-content : %p\n", debut->content);
	if (close(fd) == -1)
		return (-1);
	write(1, "333\n", 4);
	if (ft_display_file(debut, map) == -1)
		return (-1);
	write(1, "999\n", 4);
	return (0);
}



int	main(int argc, char **argv)
{
	t_env	*a;
	t_map	*b;
	int		x, ret;

	a = (t_env*)malloc(sizeof(t_env) * 1);
	b = (t_map*)malloc(sizeof(t_map) * 1);

	ret = ft_read_file(argv[1], a, b);
	if (ret == -1)
		return (-1);

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

/*	printf("valeur win = %p\n", a->win);
	mlx_expose_hook(a->win, expose_hook, &a);
	draw(a->mlx, a->win);
*/
	mlx_key_hook(a->win, my_key_funct, 0);

	mlx_loop(a->mlx);
	return (0);
}
