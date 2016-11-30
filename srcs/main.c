/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:21:10 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/30 20:25:13 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init(0);
	win = mlx_new_window(mlx, 600, 600, "First windows");
	mlx_loop(mlx);
	return (0);
}
