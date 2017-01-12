/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:42:23 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 04:48:27 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	taille;

	if (!s)
		return (NULL);
	taille = ft_strlen(s);
	if (!(ret = (char *)malloc(sizeof(char) * (taille + 1))))
		return (NULL);
	taille = -1;
	while (s[++taille] != '\0')
		ret[taille] = f(s[taille]);
	ret[taille] = '\0';
	return (ret);
}
