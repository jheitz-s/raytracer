/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 10:30:47 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/21 15:13:08 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			ft_diffuse_light(t_scene *scene, t_spot *spot, t_obj *obj,
									t_3d *color)
{
	float	coef;

	coef = ft_scalair(spot->v_light, obj->v_normal) * spot->shadow_coef;
	if (coef > 0)
	{
		ft_init3d(color,
					color->x + obj->color.x * coef * spot->color.x / 255,
					color->y + obj->color.y * coef * spot->color.y / 255,
					color->z + obj->color.z * coef * spot->color.z / 255);
	}
	(void)scene;
}
