/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 08:53:08 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 14:09:22 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H
# include <math.h>
# include "libft.h"
# define PI 3.1416

typedef struct	s_3d
{
	float		x;
	float		y;
	float		z;
}				t_3d;

typedef struct	s_sphere
{
	int			rayon;
	t_3d		in;
}				t_sphere;

typedef struct	s_plane
{
	t_3d		rotate;
	t_3d		in;
	int			raw;
	t_3d		p1;
	t_3d		p2;
	t_3d		p3;
}				t_plane;

typedef struct	s_cylinder
{
	int			rayon;
	t_3d		rotate;
	t_3d		in;
}				t_cylinder;

typedef struct	s_cone
{
	int			rayon;
	int			open;
	t_3d		rotate;
	t_3d		in;
}				t_cone;

int				ft_fact(int nb);
float			ft_max(float a, float b);
float			ft_solve_eq2(float alpha, float beta, float gama);
float			ft_pow(float x, int pow);
float			ft_scalair(t_3d v1, t_3d v2);
float			ft_norme(t_3d *o);
void			ft_normalize(t_3d *o);
void			ft_rotate(t_3d *o, int deg, char axe);
void			ft_init3d(t_3d *o, float x, float y, float z);
void			ft_apply_rotate(t_3d *o, t_3d rotate);
void			ft_apply_rotate_rev(t_3d *o, t_3d rotate);
void			ft_norme_sphere(void *obj, t_3d p_inter, t_3d *v_n, t_3d *p);
void			ft_norme_cylinder(void *obj, t_3d p_inter, t_3d *v_n, t_3d *p);
void			ft_norme_plane(void *obj, t_3d p_inter, t_3d *v_n, t_3d *p);
void			ft_norme_cone(void *obj, t_3d p_inter, t_3d *v_n, t_3d *p);
void			ft_ray_reflect(t_3d *ray, t_3d *v_normal, t_3d *reflect);

#endif
