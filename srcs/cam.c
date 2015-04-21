/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 11:04:03 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/27 17:13:44 by mapetit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_cam(t_cam *cam, t_scene *scene)
{
	if (scene->cam == 1)
	{
		ft_init3d(&cam->p_pos, scene->pos_cam.x, scene->pos_cam.y,
					scene->pos_cam.z);
		ft_init3d(&cam->rotate, scene->rot_cam.x, scene->rot_cam.y,
					scene->rot_cam.z);
	}
	else
	{
		ft_init3d(&cam->p_pos, 0., 0., 0);
		ft_init3d(&cam->rotate, 0, 0., 0.);
	}
	cam->fov = 45.;
	cam->distance = (WIDTH / 2.) / tan(cam->fov / 2.);
}
