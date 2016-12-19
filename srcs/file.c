/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 03:07:04 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/19 03:01:57 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_display_color(char *str)
{
	char	**split;

	split = ft_strsplit((char const*)str, ',');
	if (!(ft_strdigit(split[0])))
		return (0);
	free(split[1]);
	free(split[0]);
	free(split);
	return (1);
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
		if (ft_display_color(split[len]) == 0)
			exit(0);
		new[len].z = ft_atoi(split[len]);
		new[len].color = NULL;
	}
	len = -1;
	while (++len < env->col)
		free(split[len]);
	free(split);
	return (new);
}

static int		ft_display_file(char *tab, t_env *env)
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

int				ft_read_file(char *tab, t_env *env)
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
	return (0);
}
