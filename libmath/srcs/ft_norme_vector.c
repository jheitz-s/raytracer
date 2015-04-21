/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norme_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 18:42:48 by tskrzype          #+#    #+#             */
/*   Updated: 2014/03/27 13:11:54 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	ft_norme_sphere(void *obj, t_3d p_inter, t_3d *v_normal, t_3d *p_beg)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)obj;
	v_normal->x = p_inter.x - sphere->in.x;
	v_normal->y = p_inter.y - sphere->in.y;
	v_normal->z = p_inter.z - sphere->in.z;
	ft_normalize(v_normal);
	(void)p_beg;
}

void	ft_norme_cylinder(void *obj, t_3d p_inter, t_3d *v_normal, t_3d *p_beg)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)obj;
	p_inter.x = p_inter.x - cylinder->in.x;
	p_inter.y = p_inter.y - cylinder->in.y;
	p_inter.z = p_inter.z - cylinder->in.z;
	ft_apply_rotate(&p_inter, cylinder->rotate);
	v_normal->x = p_inter.x;
	v_normal->y = p_inter.y;
	v_normal->z = 0;
	ft_apply_rotate_rev(v_normal, cylinder->rotate);
	ft_normalize(v_normal);
	(void)p_beg;
}

void	ft_norme_plane(void *obj, t_3d p_inter, t_3d *v_normal, t_3d *p_beg)
{
	t_plane		*plane;
	t_3d		v_tmp;

	plane = (t_plane *)obj;
	ft_init3d(&v_tmp, p_beg->x, p_beg->y, p_beg->z);
	ft_apply_rotate(&v_tmp, plane->rotate);
	v_normal->x = 0;
	v_normal->y = 0;
	v_normal->z = (v_tmp.z < 0) ? 100 : -100;
	ft_apply_rotate_rev(v_normal, plane->rotate);
	ft_normalize(v_normal);
	(void)p_beg;
	(void)p_inter;
}

void	ft_norme_cone(void *obj, t_3d p_inter, t_3d *v_normal, t_3d *p_beg)
{
	t_cone	*cone;

	cone = (t_cone *)obj;
	ft_apply_rotate(&p_inter, cone->rotate);
	v_normal->x = p_inter.x - cone->in.x;
	v_normal->y = p_inter.y - cone->in.y;
	v_normal->z = 0;
	ft_apply_rotate_rev(v_normal, cone->rotate);
	ft_normalize(v_normal);
	(void)p_beg;
}
