/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapetit <mapetit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 19:42:34 by mapetit           #+#    #+#             */
/*   Updated: 2014/03/25 15:20:36 by mapetit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_add_perlin(t_scene *scene, t_obj *obj, t_3d *color)
{
	double	coef;
	double	freq;

	if (scene->perlin == 1 && obj->perlin == 1)
	{
		freq = noise_2d(obj->p_inter.x);
		coef = perlin(2, freq, 0.7, obj->p_inter.x);
		color->x = coef * color->x;
		color->y = coef * color->y;
		color->z = coef * color->z;
	}
}
