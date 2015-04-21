/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 17:44:29 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/21 17:44:32 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			ft_add_light(t_scene *scene, t_obj *obj, t_3d *color, t_3d *v_p)
{
	t_list	*l_spot;
	t_spot	*spot;

	l_spot = scene->spot;
	if (scene->light == 1)
	{
		ft_ambiant_light(color);
		while (l_spot != NULL)
		{
			spot = l_spot->content;
			ft_init3d(&spot->v_light, spot->p.x - obj->p_inter.x,
						spot->p.y - obj->p_inter.y, spot->p.z - obj->p_inter.z);
			spot->shadow_coef = ft_shadow(scene, obj->p_inter, spot->v_light,
											obj);
			ft_diffuse_light(scene, spot, obj, color);
			l_spot = l_spot->next;
		}
		if (obj->brightness > 0)
			ft_specular_light(scene, obj, color, v_p);
	}
}
