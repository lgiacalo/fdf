/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 00:20:07 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/09 00:20:09 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *lst, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i < nbr && lst)
	{
		lst = lst->next;
		i++;
	}
	if (i == nbr && lst)
		return (lst);
	return (NULL);
}
