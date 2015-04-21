/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 17:58:23 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/27 16:51:39 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include "libft.h"
# include "libmath.h"
# define WIDTH_SCREEN 600
# define HEIGHT_SCREEN 600
# define HEIGHT 800.0f
# define WIDTH 800.0f

typedef struct	s_coor
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			color;
}				t_coor;

typedef enum	e_type_obj
{
	sphere = 0,
	plane,
	cylinder,
	cone
}				t_type_obj;

typedef struct	s_img
{
	void		*img;
	char		*str;
	int			b_pi;
	int			s_li;
	int			endi;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
}				t_env;

typedef struct	s_cam
{
	t_3d		p_pos;
	t_3d		rotate;
	float		distance;
	float		fov;
}				t_cam;

typedef struct	s_scene
{
	t_list		*intersection;
	t_list		*object;
	t_list		*spot;
	t_list		*texture;
	t_3d		pos_cam;
	t_3d		rot_cam;
	int			x_beg;
	int			y_beg;
	int			x_end;
	int			y_end;
	int			nb_alias;
	int			light;
	int			perlin;
	int			brightness;
	int			transparency;
	int			reflexion;
	int			reflexion_rec;
	int			antialiasing;
	int			cam;
}				t_scene;

typedef struct	s_obj
{
	t_type_obj	type;
	void		*obj;
	void		*obj_tmp;
	t_3d		color;

	t_3d		p_inter;
	float		distance;

	t_3d		v_normal;
	float		brightness;
	float		transparency;
	float		reflexion;
	int			perlin;
}				t_obj;

typedef struct	s_spot
{
	t_3d		p;
	t_3d		color;
	t_3d		v_light;
	float		shadow_coef;
}				t_spot;

typedef struct	s_ray
{
	t_list		*obj;
	t_list		*intersection;
	t_obj		*obj_hit;
	t_3d		color;
	int			ret;
	t_scene		*scene;
	t_3d		p_beg;
	t_3d		v_ray;
	t_obj		*o;
}				t_ray;

/*
** Thread
*/

typedef struct	s_thread
{
	t_scene		*scene1;
	t_scene		*scene2;
	t_scene		*scene3;
	t_scene		*scene4;
	t_img		img1;
	t_img		img2;
	t_img		img3;
	t_img		img4;
	t_env		e;
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;
	pthread_t	thread4;
}				t_thread;

void			ft_init_coor_scene1(t_scene *scene1);
void			ft_init_coor_scene2(t_scene *scene2);
void			ft_init_coor_scene3(t_scene *scene3);
void			ft_init_coor_scene4(t_scene *scene4);
int				ft_init_img(t_thread *thread);
void			*ft_thread1(void *arg);
void			*ft_thread2(void *arg);
void			*ft_thread3(void *arg);
void			*ft_thread4(void *arg);

/*
** Intersection
*/

typedef float	(*t_inter_ptr)(t_obj *obj, t_3d p_beg, t_3d v_ray);

typedef struct	s_inter
{
	t_type_obj	type;
	t_inter_ptr	inter;
}				t_inter;

t_obj			*ft_find_closest_object(t_obj *current, t_obj *object);
void			ft_init_intersection(t_obj *obj);

int				ft_intersection(t_obj *obj, t_3d p_beg, t_3d v_ray);
float			ft_inter_sphere(t_obj *obj, t_3d p_beg, t_3d v_ray);
float			ft_inter_cylinder(t_obj *obj, t_3d p_beg, t_3d v_ray);
float			ft_inter_plane(t_obj *obj, t_3d p_beg, t_3d v_ray);
float			ft_inter_cone(t_obj *obj, t_3d p_beg, t_3d v_ray);

/*
** Raytracer
*/

void			ft_init_cam(t_cam *cam, t_scene *scene);
void			ft_init_raytracing(t_thread *thread);
void			ft_destroy_scene(t_scene *scene);
void			ft_put_pxl_image(t_img *img, int color, int x, int y);
void			ft_raytracing(t_scene *scene, t_img *img);
void			ft_convert_int(int color, t_3d *color_3d);
int				ft_convert_rgb(t_3d color3d);
int				ft_launch_ray(t_scene *scene, t_3d p_beg, t_3d v_ray, t_obj *o);
int				ft_secure_color(int color);
void			ft_get_obj_hit(t_ray *r, t_list *obj);
void			ft_list_inter(t_ray *ray);

/*
** Effect
*/

void			ft_init_effect(t_scene *scene);
double			noise_2d(int x);
double			perlin(int oct, double freq, double pers, double x);
void			ft_add_perlin(t_scene *scene, t_obj *obj, t_3d *color);
void			ft_add_light(t_scene *scene, t_obj *obj, t_3d *color, t_3d *v);
void			ft_add_transparency(t_scene *scene, t_3d *v_ray,
										t_3d *color, t_obj *obj);

void			ft_add_reflexion(t_scene *scene, t_3d *v_ray,
										t_3d *color, t_obj *obj);
void			ft_diffuse_light(t_scene *scene, t_spot *spot, t_obj *obj,
									t_3d *color);
void			ft_specular_light(t_scene *scene, t_obj *obj, t_3d *color,
									t_3d *v_prov);
void			ft_ambiant_light(t_3d *color);
float			ft_shadow(t_scene *scene, t_3d p_beg, t_3d v_ray, t_obj *obj);
int				ft_antialiasing(t_scene *scene, t_coor *coor, t_cam *cam);

/*
** Normal
*/

typedef void	(*t_ptr_norm)(void *, t_3d, t_3d *, t_3d *);

typedef struct	s_norm
{
	t_type_obj	type;
	t_ptr_norm	norme;
}				t_norm;

void			ft_normal(t_obj *obj, t_3d *p_beg);

#endif
