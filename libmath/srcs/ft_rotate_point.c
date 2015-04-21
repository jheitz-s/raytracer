/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:34:47 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/02/14 18:36:14 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libmath.h"

static void			ft_x_rotate_point(t_point *point, float radian)
{
	float	tmp;

	tmp = point->y;
	point->y = point->y * cos(radian) - point->z * sin(radian);
	point->z = tmp * sin(radian) + point->z * cos(radian);
}

static void			ft_y_rotate_point(t_point *point, float radian)
{
	float	tmp;

	tmp = point->x;
	point->x = point->x * cos(radian) + point->z * sin(radian);
	point->z = -tmp * sin(radian) + point->z * cos(radian);
}

static void			ft_z_rotate_point(t_point *point, float radian)
{
	float	tmp;

	tmp = point->x;
	point->x = point->x * cos(radian) - point->y * sin(radian);
	point->y = tmp * sin(radian) + point->y * cos(radian);
}

void				ft_rotate_point(t_point *point, float radian, char axe)
{
	if (radian < 0)
		radian += 360;
	if (radian > 360)
		radian -= 360;
	radian = radian * PI / 180;
	if (axe == 'x')
		ft_x_rotate_point(point, radian);
	else if (axe == 'y')
		ft_y_rotate_point(point, radian);
	else if (axe == 'z')
		ft_z_rotate_point(point, radian);
}
