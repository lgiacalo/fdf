/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 03:07:04 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/14 01:55:31 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void		ft_affichage(t_env *env);

static int	*ft_space(char *str, t_env *env)
{
	int		*new;
	char	**split;
	int		len;

	env->col = ft_nbwords(str, ' ');
	if (!(new = (int*)malloc(sizeof(int) * (env->col))))
		return (NULL);
	len = -1;
	split = ft_strsplit((char const*)str, ' ');
	while (++len < env->col)
		new[len] = ft_atoi(split[len]);
	len = -1;
	while (++len < env->col)
		free(split[len]);
	return (new);
}

static int	ft_display_file(char *tab, t_env *env)
{
	int		fd;
	int		i;
	char	*temp1;

	if (!(env->point = (int**)malloc(sizeof(int*) * (env->line + 1))))
		return (-1);
	env->point[env->line] = 0;
	i = 0;
	if ((fd = open(tab, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &temp1) == 1)
	{
		if (!(env->point[i] = ft_space(temp1, env)))
			return (-1);
		free(temp1);
		i++;
	}
	if ((close(fd) == -1))
		return (-1);
	return (0);
}

int			ft_read_file(char *tab, t_env *env)
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
	if ((i <= 0) || (close(fd) == -1))
		return (-1);
	env->line = i;
	if ((ft_display_file(tab, env) == -1))
		return (-1);
	ft_remplissage(env);
	ft_affichage(env);
	return (0);
}

void		ft_affichage(t_env *env)
{
	int	x, y;

	printf("\n\tTAILLE WINDOW\n");
	printf("VALEUR X : %f\t/\t", env->len_win.x);
	printf("VALEUR Y : %f\n\n", env->len_win.y);
	printf("\tTAILLE IMAGE\n");
	printf("VALEUR X : %f\t/\t", env->len_img.x);
	printf("VALEUR Y : %f\n\n", env->len_img.y);
	printf("Nombre de colonne : %d\n", env->col);
	printf("Nombre de ligne : %d\n\n", env->line);
	printf("Ecart entre les points : %d pixels, soit %d\n", ECT_PIX, env->ecart_case);
	printf("Longueur d'une ligne : %d\n", env->img_ptr);
	printf("Longeur de toutes les lignes : %d\n", env->len_str);
	printf("Nombre de ligne en plus (en bas et en haut) : %d\n\n", env->h_more);


	x = 0;
	while (x < env->line)
	{
		y = 0;
		while (y < env->col)
		{
			printf("%d", env->point[x][y]);
			if (env->point[x][y] < 10)
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
