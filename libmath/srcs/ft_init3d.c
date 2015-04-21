/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 12:02:47 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 12:02:50 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libmath.h>

void	ft_init3d(t_3d *o, float x, float y, float z)
{
	o->x = x;
	o->y = y;
	o->z = z;
}