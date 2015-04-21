/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 19:42:46 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/15 15:05:56 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	ft_inter_cylinder(t_obj *obj, t_3d p_beg, t_3d v_ray)
{
	t_cylinder	*cylinder;
	t_3d		p_tmp;
	t_3d		eq2;

	cylinder = (t_cylinder *)obj->obj;
	ft_init3d(&p_tmp, p_beg.x - cylinder->in.x, p_beg.y - cylinder->in.y,
				p_beg.z - cylinder->in.z);
	ft_apply_rotate(&v_ray, cylinder->rotate);
	ft_apply_rotate(&p_tmp, cylinder->rotate);
	eq2.x = ft_pow(v_ray.x, 2) + ft_pow(v_ray.y, 2);
	eq2.y = 2 * (v_ray.x * p_tmp.x + v_ray.y * p_tmp.y);
	eq2.z = ft_pow(p_tmp.x, 2) + ft_pow(p_tmp.y, 2)
				- ft_pow(cylinder->rayon, 2);
	return (ft_solve_eq2(eq2.x, eq2.y, eq2.z));
}
