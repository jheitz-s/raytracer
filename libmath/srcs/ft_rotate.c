/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 10:40:56 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/12 12:21:08 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libmath.h"

static void			ft_x_rotate(t_3d *v, float radian)
{
	float	tmp;

	tmp = v->y;
	v->y = v->y * cos(radian) - v->z * sin(radian);
	v->z = tmp * sin(radian) + v->z * cos(radian);
}

static void			ft_y_rotate(t_3d *v, float radian)
{
	float	tmp;

	tmp = v->x;
	v->x = v->x * cos(radian) + v->z * sin(radian);
	v->z = -tmp * sin(radian) + v->z * cos(radian);
}

static void			ft_z_rotate(t_3d *v, float radian)
{
	float	tmp;

	tmp = v->x;
	v->x = v->x * cos(radian) - v->y * sin(radian);
	v->y = tmp * sin(radian) + v->y * cos(radian);
}

void				ft_rotate(t_3d *v, int deg, char axe)
{
	float	radian;

	radian = 0;
	if (deg < 0)
		deg += 360;
	if (deg >= 360)
		deg -= 360;
	radian = (float)deg * PI / 180;
	if (axe == 'x')
		ft_x_rotate(v, radian);
	else if (axe == 'y')
		ft_y_rotate(v, radian);
	else if (axe == 'z')
		ft_z_rotate(v, radian);
}
