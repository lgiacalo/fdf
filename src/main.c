/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:21:10 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/01/12 06:11:38 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_no_leaks(t_env **env)
{
	int	y;

	y = 0;
	while (y < (*env)->len_map.y)
	{
		free((*env)->map[y]);
		y++;
	}
	free((*env)->map);
	free(*env);
	env = NULL;
}

int		my_key_funct(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		ft_no_leaks(&env);
		exit(0);
	}
	if (keycode == 126)
		env->pos_y = -3;
	if (keycode == 125)
		env->pos_y = 3;
	if (keycode == 123)
		env->pos_x = -3;
	if (keycode == 124)
		env->pos_x = 3;
	return (1);
}

int		ft_loop(t_env *env)
{
	static double	x = 0;
	static double	y = 0;

	x += env->pos_x;
	y += env->pos_y;
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win, env->img, (int)x, (int)y);
	env->pos_x *= 0.95;
	env->pos_y *= 0.95;
	return (1);
}

int		ft_mlx_init_img(t_env *env)
{
	if (!(env->mlx = mlx_init(0)))
		return (EXIT_FAILURE);
	if ((!(env->win = mlx_new_window(env->mlx, (env->len_img.x + 100),
						(env->len_img.y + 100), "FDF"))))
		return (EXIT_FAILURE);
	if (!(env->img = mlx_new_image(env->mlx, env->len_img.x, env->len_img.y)))
		return (EXIT_FAILURE);
	if (!(env->str = mlx_get_data_addr(env->img, &(env->bit_per_pixel),
					&(env->img_ptr), &(env->endian))))
		return (EXIT_FAILURE);
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 2)
	{
		if (!(env = (t_env*)malloc(sizeof(t_env) * 1)))
			ft_malloc_error();
		ft_display_file(env, argv[1]);
		ft_remplissage(env);
		ft_mlx_init_img(env);
		ft_grid_line(env);
		ft_grid_col(env);
		mlx_key_hook(env->win, &my_key_funct, env);
		mlx_loop_hook(env->mlx, &ft_loop, env);
		mlx_loop(env->mlx);
	}
	return (0);
}
