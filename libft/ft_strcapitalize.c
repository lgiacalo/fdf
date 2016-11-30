/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 06:14:07 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/14 20:22:10 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 1;
	if (!str)
		return (NULL);
	ft_strlowcase(str);
	if (str[0] != '\0' && str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if ((str[i - 1] > 'z' || str[i - 1] < 'a')
				&& (str[i - 1] > '9' || str[i - 1] < '0')
				&& (str[i - 1] > 'Z' || str[i - 1] < 'A'))
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		i++;
	}
	return (str);
}
