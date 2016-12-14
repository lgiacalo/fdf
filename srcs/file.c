/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 03:07:04 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/14 23:26:01 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void		ft_affichage(t_env *env);

static char	*ft_display_color(char *str)
{
	char	*new;
	char	**split;

	split = ft_strsplit((char const*)str, ',');
	new = split[1];
	free(split[0]);
	free(split);
	return (new);
}

static t_point	*ft_space(char *str, t_env *env, int y)
{
	t_point	*new;
	char	**split;
	int		len;

	env->col = ft_nbwords(str, ' ');
	if (!(new = (t_point*)malloc(sizeof(t_point) * (env->col))))
		return (NULL);
	len = -1;
	split = ft_strsplit((char const*)str, ' ');
	while (++len < env->col)
	{
		new[len].x = len;
		new[len].y = y;
		new[len].z = ft_atoi(split[len]);
		if (!(ft_strdigit(split[len])))
			new[len].color = ft_display_color(split[len]);
		else
			new[len].color = NULL;
	}
	len = -1;
	while (++len < env->col)
		free(split[len]);
	free(split);
	return (new);
}

static int	ft_display_file(char *tab, t_env *env)
{
	int		fd;
	int		i;
	char	*temp1;

	if (!(env->point = (t_point**)malloc(sizeof(t_point*) * (env->line + 1))))
		return (-1);
	env->point[env->line] = 0;
	i = 0;
	if ((fd = open(tab, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &temp1) == 1)
	{
		if (!(env->point[i] = ft_space(temp1, env, i)))
		{
			free(temp1);
			return (-1);
		}
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
			printf("%.0f", env->point[x][y].z);
		//	printf(" %.0f", env->point[x][y].x);
		//	printf(" %.0f", env->point[x][y].y);
			if (env->point[x][y].color)
				printf(",%s", env->point[x][y].color);
			if (env->point[x][y].z < 10)
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
