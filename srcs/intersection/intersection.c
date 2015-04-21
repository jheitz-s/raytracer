/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 18:17:22 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/15 18:16:52 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_init_tab(t_inter *tab_inter)
{
	tab_inter[0].type = sphere;
	tab_inter[0].inter = ft_inter_sphere;
	tab_inter[1].type = plane;
	tab_inter[1].inter = ft_inter_plane;
	tab_inter[2].type = cylinder;
	tab_inter[2].inter = ft_inter_cylinder;
	tab_inter[3].type = cone;
	tab_inter[3].inter = ft_inter_cone;
}

t_obj		*ft_find_closest_object(t_obj *current, t_obj *object)
{
	if (object == NULL)
		return (current);
	else
	{
		if (object->distance > current->distance)
			return (current);
		else
			return (object);
	}
}

int			ft_intersection(t_obj *obj, t_3d p_beg, t_3d v_ray)
{
	static int		init = 0;
	static t_inter	tab_inter[4];
	float			coef;
	t_3d			tmp;

	coef = -1;
	obj->distance = -1;
	if (init == 0)
	{
		ft_init_tab(tab_inter);
		init = 1;
	}
	coef = tab_inter[(int)obj->type].inter(obj, p_beg, v_ray);
	if (coef == -1)
		return (0);
	else
	{
		ft_init3d(&obj->p_inter, p_beg.x + v_ray.x * coef,
					p_beg.y + v_ray.y * coef, p_beg.z + v_ray.z * coef);
		ft_init3d(&tmp, obj->p_inter.x - p_beg.x, obj->p_inter.y - p_beg.y,
					obj->p_inter.z - p_beg.z);
		obj->distance = ft_norme(&tmp);
	}
	return (1);
}
