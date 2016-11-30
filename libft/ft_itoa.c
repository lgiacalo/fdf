/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:24:54 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 04:54:38 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*ret;
	int			len;
	long int	nbr;

	len = ft_len_numbers(n);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nbr = n;
	ret[0] = '0';
	ret[len] = '\0';
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ret[0] = '-';
	}
	while (nbr > 0)
	{
		ret[len - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (ret);
}
