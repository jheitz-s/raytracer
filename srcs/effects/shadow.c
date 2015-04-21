/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 16:40:31 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 15:05:18 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float			ft_shadow(t_scene *scene, t_3d p_beg, t_3d v_ray, t_obj *obj)
{
	t_ray	ray;

	ray.o = obj;
	ray.p_beg = p_beg;
	ray.v_ray = v_ray;
	ray.obj = scene->object;
	ray.obj_hit = NULL;
	ray.ret = 0;
	ray.intersection = scene->intersection;
	ft_list_inter(&ray);
	ft_get_obj_hit(&ray, scene->object);
	if (ray.obj_hit != NULL && ray.obj_hit->distance < ft_norme(&v_ray))
	{
		if (scene->transparency == 0 || ray.obj_hit->transparency == 0)
			return (0.);
		else
			return ((ray.obj_hit->transparency / 100.)
			* ft_shadow(scene, ray.obj_hit->p_inter,
			v_ray, ray.obj_hit));
	}
	return (1);
}
