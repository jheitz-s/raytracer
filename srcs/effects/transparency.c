/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 11:10:23 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 15:05:28 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_add_transparency(t_scene *scene, t_3d *v_ray, t_3d *c, t_obj *obj)
{
	int		color;
	t_3d	nc;
	float	coef;

	if (scene->transparency == 1)
	{
		coef = obj->transparency;
		color = 0;
		if (coef != 0)
		{
			color = ft_launch_ray(scene, obj->p_inter, *v_ray, obj);
			ft_convert_int(color, &nc);
			c->x = ((100 - coef) / 100) * c->x + (coef / 100) * nc.x;
			c->y = ((100 - coef) / 100) * c->y + (coef / 100) * nc.y;
			c->z = ((100 - coef) / 100) * c->z + (coef / 100) * nc.z;
		}
	}
}
