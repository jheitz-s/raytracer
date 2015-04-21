/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 13:39:08 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/22 10:50:54 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_specular_light(t_scene *scene, t_obj *obj, t_3d *c, t_3d *v_p)
{
	t_list	*l_spot;
	t_spot	*spot;
	t_3d	v_reflect;
	t_3d	v_neg_prov;
	float	coef;

	if (scene->brightness == 1)
	{
		l_spot = scene->spot;
		ft_init3d(&v_neg_prov, -v_p->x, -v_p->y, -v_p->z);
		coef = 0;
		while (l_spot != NULL)
		{
			spot = l_spot->content;
			ft_ray_reflect(&spot->v_light, &obj->v_normal, &v_reflect);
			coef = ft_scalair(v_reflect, v_neg_prov) * spot->shadow_coef;
			if (coef >= 0)
			{
				c->x += (obj->brightness / 100) * spot->color.x * pow(coef, 70);
				c->y += (obj->brightness / 100) * spot->color.y * pow(coef, 70);
				c->z += (obj->brightness / 100) * spot->color.z * pow(coef, 70);
			}
			l_spot = l_spot->next;
		}
	}
}
