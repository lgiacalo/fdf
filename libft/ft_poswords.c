/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poswords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 04:13:05 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 04:53:36 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_poswords(char const *s, char c)
{
	int	*tab;
	int i;
	int emp;

	i = ft_nbwords(s, c);
	if (!(tab = (int*)malloc(sizeof(*tab) * (i + 1))))
		return (NULL);
	i = 0;
	emp = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (tab);
		tab[emp] = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		emp++;
	}
	return (tab);
}
