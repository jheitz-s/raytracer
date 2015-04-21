/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 19:40:54 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 11:59:21 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static float	ft_calc_vec(t_3d *a, t_3d *b, t_3d *c)
{
	return ((a->x - c->x) * (b->y - c->y) - (a->y - c->y) * (b->x - c->x));
}

static float	ft_raw(float k, t_plane *plane, t_3d p_beg, t_3d v_ray)
{
	t_3d	p_tmp;
	t_3d	p_in;
	float	a;
	float	b;
	float	c;

	ft_init3d(&p_in, 0, 0, 0);
	ft_init3d(&p_tmp, p_beg.x + k * v_ray.x, p_beg.y + k * v_ray.y, 0);
	a = ft_calc_vec(&plane->p1, &plane->p2, &p_tmp);
	b = ft_calc_vec(&plane->p2, &p_in, &p_tmp);
	c = ft_calc_vec(&p_in, &plane->p1, &p_tmp);
	if ((a > 0 && b > 0 && c > 0) || (a < 0 && b < 0 && c < 0))
		return (k);
	return (-1);
	(void)plane;
}

float			ft_inter_plane(t_obj *obj, t_3d p_beg, t_3d v_ray)
{
	t_plane	*plane;
	float	k;

	plane = (t_plane *)obj->obj;
	ft_init3d(&p_beg, p_beg.x - plane->in.x, p_beg.y - plane->in.y
				, p_beg.z - plane->in.z);
	ft_apply_rotate(&v_ray, plane->rotate);
	ft_apply_rotate(&p_beg, plane->rotate);
	if (v_ray.z < 0.0000001 && v_ray.z > -0.0000001)
		return (-1);
	k = -p_beg.z / v_ray.z;
	if (k < -0.0000001)
		return (-1);
	if (plane->raw == 1)
		return (ft_raw(k, plane, p_beg, v_ray));
	return (k);
}
