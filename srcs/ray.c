/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:36:33 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/25 15:04:36 by mapetit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "rt.h"

void	ft_get_color(t_scene *scene, t_3d *color, t_3d *v_prov, t_obj *obj_hit)
{
	if (obj_hit != NULL)
	{
		ft_normal(obj_hit, v_prov);
		ft_init3d(color, obj_hit->color.x, obj_hit->color.y, obj_hit->color.z);
		ft_add_perlin(scene, obj_hit, color);
		ft_add_light(scene, obj_hit, color, v_prov);
		ft_add_reflexion(scene, v_prov, color, obj_hit);
		ft_add_transparency(scene, v_prov, color, obj_hit);
	}
}

void	ft_get_obj_hit(t_ray *r, t_list *obj)
{
	while (obj != NULL)
	{
		if (obj->content != r->o)
		{
			r->ret = ft_intersection(obj->content, r->p_beg, r->v_ray);
			if (r->ret == 1)
				r->obj_hit = ft_find_closest_object(obj->content, r->obj_hit);
		}
		obj = obj->next;
	}
}

void	ft_list_inter(t_ray *ray)
{
	while (ray->intersection != NULL)
	{
		ray->obj = ray->intersection->content;
		ray->ret = ft_intersection(ray->obj->content, ray->p_beg, ray->v_ray);
		if (ray->ret == 1)
		{
			ray->obj = ray->obj->next;
			ft_get_obj_hit(ray, ray->obj);
		}
		ray->intersection = ray->intersection->next;
	}
}

int		ft_launch_ray(t_scene *scene, t_3d p_beg, t_3d v_ray, t_obj *o)
{
	t_3d	color;
	t_ray	ray;

	ray.o = o;
	ray.p_beg = p_beg;
	ray.v_ray = v_ray;
	ray.obj = scene->object;
	ray.obj_hit = NULL;
	ray.ret = 0;
	ft_init3d(&color, 0, 0, 0);
	ray.intersection = scene->intersection;
	ft_list_inter(&ray);
	ft_get_obj_hit(&ray, scene->object);
	ft_get_color(scene, &color, &v_ray, ray.obj_hit);
	return (ft_convert_rgb(color));
}
