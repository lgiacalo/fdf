/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:48:56 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 04:52:53 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_strlen_nb_lettres(char const *s, char c, int i)
{
	int j;

	j = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb_mots;
	int		i;
	int		k;
	int		*tab;
	char	**dest;

	if (!s)
		return (NULL);
	nb_mots = ft_nbwords(s, c);
	if (!(dest = (char**)malloc(sizeof(char*) * nb_mots + 1)))
		return (NULL);
	i = -1;
	tab = ft_poswords(s, c);
	while (++i < nb_mots)
	{
		k = -1;
		dest[i] = (char*)malloc(sizeof(char)
				* ft_strlen_nb_lettres(s, c, tab[i]) + 1);
		while (++k < ft_strlen_nb_lettres(s, c, tab[i]))
			dest[i][k] = s[tab[i] + k];
		dest[i][k] = '\0';
	}
	dest[i] = 0;
	free(tab);
	return (dest);
}
