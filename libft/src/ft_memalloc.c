/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:25:38 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 04:45:06 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	if (!(tab = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	while (i < size)
	{
		*(unsigned char*)(tab + i) = '\0';
		i++;
	}
	return (tab);
}
