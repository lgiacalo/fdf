/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 10:40:53 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/01/12 06:10:04 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_exit_fdf(void)
{
	exit(1);
}

void	ft_malloc_error(void)
{
	ft_putstr("Erreur Malloc\n");
	ft_exit_fdf();
}

void	ft_read_error(void)
{
	ft_putstr("Erreur Fichier (Lecture/Fermeture)\n");
	ft_exit_fdf();
}

void	ft_bad_file(void)
{
	ft_putstr("Mauvais fichier\n");
	ft_exit_fdf();
}
