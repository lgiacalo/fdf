/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 01:20:36 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/01/12 06:12:16 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_nbr_lines(char *str)
{
	char	buf;
	int		nbr_lines;
	int		fd;
	int		ret;

	nbr_lines = 0;
	((fd = open(str, O_RDONLY)) <= 0) ? ft_read_error() : 0;
	while (((ret = read(fd, &buf, 1)) > 0))
	{
		if (buf == '\n')
		{
			nbr_lines++;
			(nbr_lines > 5000) ? ft_exit_fdf() : 0;
		}
	}
	if (ret < 0)
		ft_read_error();
	(buf != '\n') ? nbr_lines++ : 0;
	if (close(fd) == -1)
		ft_read_error();
	return (nbr_lines);
}

int		ft_strlen_double(char **str)
{
	int	nbr_lines;

	nbr_lines = 0;
	while (*str != 0 && **str != '\0')
	{
		nbr_lines++;
		str++;
	}
	return (nbr_lines);
}

void	ft_display_lines(t_env *env, char **chaine, int y)
{
	char	**split;
	int		x;

	split = ft_strsplit(*chaine, ' ');
	if ((x = ft_strlen_double(split)) != env->len_map.x)
		(env->len_map.x == -42) ? env->len_map.x = x : ft_bad_file();
	if (!(env->map[y] = (t_map*)malloc(sizeof(t_map) * x)))
		ft_malloc_error();
	x = 0;
	while (x < env->len_map.x)
	{
		ft_display_color(split[x], env->map[y][x].color);
		env->map[y][x].z = ft_atoi(split[x]);
		free(split[x]);
		split[x] = NULL;
		x++;
	}
	if (split[x])
		free(split[x]);
	free(split);
	split = NULL;
}

void	ft_display_file(t_env *env, char *str)
{
	char	*chaine;
	int		fd;
	int		num_lines;

	chaine = NULL;
	num_lines = 0;
	env->len_map.y = ft_nbr_lines(str);
	env->len_map.x = -42;
	if (!(env->map = (t_map**)malloc(sizeof(t_map*) * (env->len_map.y + 1))))
		ft_malloc_error();
	env->map[env->len_map.y] = 0;
	((fd = open(str, O_RDONLY)) <= 0) ? ft_read_error() : 0;
	while (num_lines < env->len_map.y)
	{
		get_next_line(fd, &chaine);
		ft_display_lines(env, &chaine, num_lines);
		free(chaine);
		chaine = NULL;
		num_lines++;
	}
	if (close(fd) == -1)
		ft_read_error();
}
