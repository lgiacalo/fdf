/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:21:10 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/16 18:00:18 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int			my_key_funct(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void		ft_no_leaks(t_env **a)
{
	int	x;
	int	y;

	x = -1;
	while (++x < (*a)->line)
	{
		y = -1;
		while (++y < (*a)->col)
			if ((*a)->point[x][y].color)
				free((*a)->point[x][y].color);
		free((*a)->point[x]);
	}
	free((*a)->point);
	free(*a);
	a = NULL;
}

static void	ft_grillage_line(t_env *env)
{
	int		x;
	int		y;
	char	*coleur;

	y = -1;
	while (++y < env->line)
	{
		x = -1;
		while (++x < env->col - 1)
		{
			if (env->point[y][x].color)
			{
//				coleur = ft_cpy_mod(env->point[y][x].color);
				coleur = env->point[y][x].color;
			}
			else
			{
				coleur = env->point[y][x + 1].color;
//				coleur = ft_cpy_mod(env->point[y][x + 1].color);
			}
			ft_trait(env, ft_conv_point(env, x, y),
					ft_conv_point(env, (x + 1), y), coleur);
//			if (coleur)
	//			free(coleur);
		}
	}
}

static void	ft_grillage_col(t_env *env)
{
	int		x;
	int		y;
	char	*coleur;

	y = -1;
	while (++y < env->line - 1)
	{
		x = -1;
		while (++x < env->col)
		{
			if (env->point[y][x].color)
			{
				coleur =env->point[y][x].color;
//				coleur = ft_cpy_mod(env->point[y][x].color);
			}
			else
			{
				coleur = env->point[y + 1][x].color;
//				coleur = ft_cpy_mod(env->point[y + 1][x].color);
			}
			ft_trait(env, ft_conv_point(env, x, y),
					ft_conv_point(env, x, (y + 1)), coleur);
//			if (coleur)
//				free(coleur);
		}
	}
}

int			main(int argc, char **argv)
{
	t_env	*a;
	int		ret;

	if (argc == 2)
	{
		a = (t_env*)malloc(sizeof(t_env) * 1);
		ret = ft_read_file(argv[1], a);
		if (ret == -1)
			return (-1);
		if (!(a->mlx = mlx_init(0)) ||
			(!(a->img = mlx_new_image(a->mlx, a->len_img.x, a->len_img.y))))
			return (EXIT_FAILURE);
		if (!(a->str = mlx_get_data_addr(a->img, &(a->bit_per_pixel),
			&(a->img_ptr), &(a->endian))) || (!(a->win = mlx_new_window(a->mlx,
			a->len_win.x, a->len_win.y, "FDF"))))
			return (EXIT_FAILURE);
		ft_grillage_line(a);
		ft_putstr("je suis la ! 1\n");
		ft_grillage_col(a);
		ft_putstr("je suis la ! 2\n");

		mlx_put_image_to_window(a->mlx, a->win, a->img, 50, 50);
		ft_putstr("je suis la ! 3\n");
		mlx_key_hook(a->win, my_key_funct, 0);
		ft_putstr("je suis la ! 4\n");
		ft_no_leaks(&a);
		ft_putstr("je suis la ! 5\n");
		mlx_loop(a->mlx);
		ft_putstr("je suis la ! 6\n");
	}
	return (0);
}
