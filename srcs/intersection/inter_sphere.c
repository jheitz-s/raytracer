/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 19:39:21 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 11:46:51 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	ft_inter_sphere(t_obj *obj, t_3d p_beg, t_3d v_ray)
{
	t_sphere	*sphere;
	t_3d		p_tmp;
	t_3d		eq2;

	sphere = (t_sphere *)obj->obj;
	ft_init3d(&p_tmp, p_beg.x - sphere->in.x, p_beg.y - sphere->in.y,
				p_beg.z - sphere->in.z);
	eq2.x = ft_pow(v_ray.x, 2) + ft_pow(v_ray.y, 2) + ft_pow(v_ray.z, 2);
	eq2.y = 2 * (v_ray.x * p_tmp.x + v_ray.y * p_tmp.y + v_ray.z * p_tmp.z);
	eq2.z = ft_pow(p_tmp.x, 2) + ft_pow(p_tmp.y, 2) + ft_pow(p_tmp.z, 2)
					- ft_pow(sphere->rayon, 2);
	return (ft_solve_eq2(eq2.x, eq2.y, eq2.z));
}
