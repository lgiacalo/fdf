/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 03:07:04 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/14 23:40:06 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char		*ft_display_color(char *str)
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
