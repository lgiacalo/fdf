/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 03:07:04 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/09 04:36:31 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

char	*ft_space(char *str)
{
	char	*new;
	int	len;
	int	i;

	i = -1;
	len = 0;
	while (str[+i] != '\0')
		if (str[i] != ' ')
			len++;
	new = (char*)malloc(sizeof(char) * (len + 1));
	new[len] = '\0';
	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			new[len] = str[i];
			len++;
		}
		i++;
	}
	return (new);
}

int	ft_display_file(char *tab, t_env *env, t_map *map)
{
	int	fd;
	int	i;
	char	*temp1;
	char	*temp2;

	if ((map->point = (char**)malloc(sizeof(char*) * (map->line + 1))) == NULL)
		return (-1);
	map->point[map->line] = 0;
	i = 0;
	if ((fd = open(tab, O_RDONLY)) == -1)
		return (-1);
	temp2 = NULL;
	while (get_next_line(fd, &temp1) == 1)
	{
		map->point[i] = temp1;
		printf("ligne %d : %s\n", i, temp1);
//		temp2 = temp1;
//		map->point[i] = ft_space(temp2);
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
	i = 0;
	printf("\n");
	ft_print_words_tables(map->point);
	printf("\n");
	return (0);
}
