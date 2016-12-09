/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 03:07:04 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/09 06:05:50 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	*ft_space(char *str, t_map *map)
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

int	ft_display_file(char *tab, t_env *env, t_map *map)
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


int	ft_read_file(char *tab, t_env *env, t_map *map)
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
	return (0);
}
