/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:41:55 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 04:49:50 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		ret[taille] = f(taille, s[taille]);
	ret[taille] = '\0';
	return (ret);
}
