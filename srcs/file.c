/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 03:07:04 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/11 21:16:32 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	ft_affichage(t_env *env, t_map *map);

static int	*ft_space(char *str, t_map *map)
{
	int	*new;
	char	**split;
	int	len;

	map->col = ft_nbwords(str, ' ');
	if (!(new = (int*)malloc(sizeof(int) * (map->col))))
		return (NULL);
	len = -1;
	split = ft_strsplit((char const*)str, ' ');
	while (++len < map->col)
		new[len] = ft_atoi(split[len]);
	len = -1;
	while (++len < map->col)
		free(split[len]);
	return (new);
}

static int	ft_display_file(char *tab, t_env *env, t_map *map)
{
	int	fd;
	int	i;
	char	*temp1;

	if (!(map->point = (int**)malloc(sizeof(int*) * (map->line + 1))))
		return (-1);
	map->point[map->line] = 0;
	i = 0;
	if ((fd = open(tab, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &temp1) == 1)
	{
		if (!(map->point[i] = ft_space(temp1, map)))
			return (-1);
		free(temp1);
		i++;
	}
	if ((close(fd) == -1))
		return (-1);
	return (0);
}

static void	ft_len_map(t_env *env, t_map *map)
{
	int	x;
	int	y;
	int	h;

	x = -1;
	h = 0;
	while (++x < map->line)
	{
		y = -1;
		h = 0;
		while (++y < map->col)
			if (ABS(h) < ABS(map->point[x][y]))
				h = ABS(map->point[x][y]);
		if (h > (MIN(x, (map->line - x)) * ECT_PIX / 3))
			if (map->h_more < (h - MIN(x, (map->line - x))
				* ECT_PIX / 3))
				map->h_more = h - MIN(x, (map->line - x))
				* ECT_PIX / 3;
	}
}

static void	ft_remplissage(t_env *env, t_map *map)
{
	env->bit_per_pixel = BIT_PER_PIXEL;
	env->endian = ENDIAN;
	env->img_ptr = map->col * (ECART_CASE + 4) + ECART_CASE;
	
	map->ecart_case = ECART_CASE;
	map->h_more = 0;
	ft_len_map(env, map);
	env->len_str = (2 * (map->h_more*env->img_ptr) +
	(env->img_ptr *(map->line + ((map->line - 1) * ECT_PIX))));
	env->len_img.x = ECT_PIX + map->col + (map->col * ECT_PIX);
	env->len_img.y = (2 * map->h_more) + map->line +
	((map->line - 1) * ECT_PIX);
	env->len_win.x = env->len_img.x + 100;
	env->len_win.y = env->len_img.y + 100;

}

int		ft_read_file(char *tab, t_env *env, t_map *map)
{
	int		fd;
	int		i;
	char	*temp2;

	if ((fd = open(tab, O_RDONLY)) == -1)
		return (-1);
	i = 0;
	while (get_next_line(fd, &temp2) == 1)
	{
		free(temp2);
		i++;
	}
	map->line = i;
	if ((close(fd) == -1))
		return (-1);
	if ((ft_display_file(tab, env, map) == -1))
		return (-1);
	ft_remplissage(env, map);
	ft_affichage(env, map);
	return (0);
}

void	ft_affichage(t_env *env, t_map *map)
{
	int	x, y;

	printf("\n\tTAILLE WINDOW\n");
	printf("VALEUR X : %d\t/\t", env->len_win.x);
	printf("VALEUR Y : %d\n\n", env->len_win.y);
	printf("\tTAILLE IMAGE\n");
	printf("VALEUR X : %d\t/\t", env->len_img.x);
	printf("VALEUR Y : %d\n\n", env->len_img.y);
	printf("Nombre de colonne : %d\n", map->col);
	printf("Nombre de ligne : %d\n\n", map->line);
	printf("Ecart entre les points : %d pixels, soit %d\n", ECT_PIX, map->ecart_case);
	printf("Longueur d'une ligne : %d\n", env->img_ptr);
	printf("Longeur de toutes les lignes : %d\n\n", env->len_str);
	printf("Nombre de ligne en plus (en bas et en haut) : %d\n\n", map->h_more);


	x = 0;
	y = 0;
	while (x < map->line)
	{
		y = 0;
		while (y < map->col)
		{
			printf("%d", map->point[x][y]);
			if (map->point[x][y] < 10)
				printf(" ");
			printf(" ");
			y++;
		}
		printf("\n");
		x++;
	}
	printf("\n");
	printf("\tCOULEURS\n");

	printf("Valeur en int de la couleur rouge : %d\n", mlx_get_color_value(env->mlx, 0xFF0000));
	printf("Valeur en int de la couleur blanc : %d\n", mlx_get_color_value(env->mlx, 0xFFFFFF));
	printf("Valeur en int de la couleur bleu : %d\n\n", mlx_get_color_value(env->mlx, 0x0000FF));
}
