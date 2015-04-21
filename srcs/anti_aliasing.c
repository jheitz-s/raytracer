/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 18:14:43 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 11:24:35 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_moy(int *color, int n)
{
	int		i;
	int		red;
	int		blue;
	int		green;
	t_3d	tmp;

	i = 0;
	red = 0;
	blue = 0;
	green = 0;
	while (i < n)
	{
		ft_convert_int(color[i], &tmp);
		blue += (int)tmp.x;
		green += (int)tmp.y;
		red += (int)tmp.z;
		i++;
	}
	tmp.x = blue / n;
	tmp.y = green / n;
	tmp.z = red / n;
	return (ft_convert_rgb(tmp));
}

int			ft_antialiasing(t_scene *scene, t_coor *coor, t_cam *cam)
{
	t_3d	ray;
	int		i;
	int		j;
	int		k;
	int		*color;

	i = 0;
	k = 0;
	color = (int *)malloc(sizeof(int) * (scene->nb_alias * scene->nb_alias));
	while (i < scene->nb_alias)
	{
		j = 0;
		while (j < scene->nb_alias)
		{
			ft_init3d(&ray, (float)(-WIDTH / 2.) + (float)coor->x2 + 0.20
						* (float)j, (float)cam->distance, (float)(HEIGHT / 2.)
						- (float)coor->y2 + 0.20 * (float)i);
			ft_apply_rotate(&ray, cam->rotate);
			color[k] = ft_launch_ray(scene, cam->p_pos, ray, NULL);
			j++;
			k++;
		}
		i++;
	}
	return (ft_moy(color, scene->nb_alias * scene->nb_alias));
}
