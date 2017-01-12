/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbwords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 04:11:58 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 04:53:28 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_nbwords(char const *s, char c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (nb);
		while (s[i] != '\0' && s[i] != c)
			i++;
		nb++;
	}
	return (nb);
}
