/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 11:19:56 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/21 17:44:36 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_add_reflexion(t_scene *scene, t_3d *v_ray, t_3d *color, t_obj *obj)
{
	t_3d	reflect;
	int		int_color;
	float	coef;

	if (scene->reflexion == 1 && obj->reflexion > 0 && scene->reflexion_rec > 0)
	{
		coef = obj->reflexion;
		ft_ray_reflect(v_ray, &obj->v_normal, &reflect);
		reflect.x = -reflect.x;
		reflect.y = -reflect.y;
		reflect.z = -reflect.z;
		scene->reflexion_rec--;
		int_color = ft_launch_ray(scene, obj->p_inter, reflect, obj);
		ft_convert_int(int_color, &reflect);
		color->x = ((100 - coef) / 100) * color->x + (coef / 100) * reflect.x;
		color->y = ((100 - coef) / 100) * color->y + (coef / 100) * reflect.y;
		color->z = ((100 - coef) / 100) * color->z + (coef / 100) * reflect.z;
	}
}
