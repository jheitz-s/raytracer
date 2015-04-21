/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 18:14:43 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/27 16:48:06 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_expose_hook(t_thread *t)
{
	mlx_put_image_to_window(t->e.mlx, t->e.win, t->img1.img, 0, 0);
	return (0);
}

static int	ft_key_hook(int keycode, t_thread *thread)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(thread->e.mlx, thread->e.win);
		exit(0);
	}
	return (0);
}

void		ft_raytracing(t_scene *scene, t_img *img)
{
	t_cam	cam;
	t_3d	ray;
	t_coor	coor;

	coor.y2 = 0;
	ft_init_cam(&cam, scene);
	ft_init_effect(scene);
	while (coor.y2 < HEIGHT)
	{
		coor.x2 = scene->x_beg;
		while (coor.x2 < WIDTH)
		{
			ft_init3d(&ray, (float)(-WIDTH / 2.) + (float)coor.x2, cam.distance,
						(float)(HEIGHT / 2.) - (float)coor.y2);
			ft_apply_rotate(&ray, cam.rotate);
			scene->reflexion_rec = 5;
			if (scene->nb_alias == 0)
				coor.color = ft_launch_ray(scene, cam.p_pos, ray, NULL);
			else
				coor.color = ft_antialiasing(scene, &coor, &cam);
			ft_put_pxl_image(img, coor.color, coor.x2, coor.y2);
			coor.x2 = coor.x2 + 4;
		}
		coor.y2 = coor.y2 + 1;
	}
}

void		ft_init_raytracing(t_thread *thread)
{
	thread->e.win = mlx_new_window(thread->e.mlx, WIDTH, HEIGHT, "Raytracer");
	if (thread->e.win != NULL)
	{
		ft_init_coor_scene1(thread->scene1);
		ft_init_coor_scene2(thread->scene2);
		ft_init_coor_scene3(thread->scene3);
		ft_init_coor_scene4(thread->scene4);
		if ((ft_init_img(thread)) != -1)
		{
			pthread_create(&thread->thread1, NULL, ft_thread1, thread);
			pthread_create(&thread->thread2, NULL, ft_thread2, thread);
			pthread_create(&thread->thread3, NULL, ft_thread3, thread);
			pthread_create(&thread->thread4, NULL, ft_thread4, thread);
			pthread_join(thread->thread1, NULL);
			pthread_join(thread->thread2, NULL);
			pthread_join(thread->thread3, NULL);
			pthread_join(thread->thread4, NULL);
			mlx_key_hook(thread->e.win, ft_key_hook, thread);
			mlx_expose_hook(thread->e.win, ft_expose_hook, thread);
			mlx_loop(thread->e.mlx);
		}
	}
	else
		ft_putendl_fd("raytracer: error: Can't launch mlx.", 2);
}
