/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 19:42:10 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/14 14:17:40 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	ft_inter_cone(t_obj *obj, t_3d p_beg, t_3d v_ray)
{
	t_cone	*cone;
	t_3d	p_tmp;
	t_3d	eq2;

	cone = (t_cone *)obj->obj;
	ft_init3d(&p_tmp, p_beg.x - cone->in.x, p_beg.y - cone->in.y,
				p_beg.z - cone->in.z);
	ft_apply_rotate(&v_ray, cone->rotate);
	ft_apply_rotate(&p_tmp, cone->rotate);
	eq2.x = ft_pow(v_ray.x, 2) + ft_pow(v_ray.y, 2)
				- (ft_pow(v_ray.z, 2) * (cone->open) / 100);
	eq2.y = 2 * (p_tmp.x * v_ray.x + p_tmp.y * v_ray.y
				- ((p_tmp.z * v_ray.z) * (cone->open) / 100));
	eq2.z = ft_pow(p_tmp.x, 2) + ft_pow(p_tmp.y, 2)
				- (ft_pow(p_tmp.z, 2) * (cone->open) / 100);
	return (ft_solve_eq2(eq2.x, eq2.y, eq2.z));
}
