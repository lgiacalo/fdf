/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:40:30 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 04:50:57 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		k;

	k = 0;
	if (!(s1) || !(s2))
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
						ft_strlen(s2) + 1))))
		return (NULL);
	while (s1 && *s1)
	{
		ret[k++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		ret[k++] = *s2;
		s2++;
	}
	ret[k] = '\0';
	return (ret);
}
