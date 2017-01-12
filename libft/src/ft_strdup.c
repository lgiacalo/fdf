/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:39:28 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 04:20:49 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	taille;
	char	*s2;
	int		i;

	i = -1;
	taille = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (taille + 1));
	if (s2 == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}
