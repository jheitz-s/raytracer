/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htang <htang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 11:12:59 by htang             #+#    #+#             */
/*   Updated: 2014/03/26 11:43:06 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_change_min_max(t_3d *min, t_3d *max, t_3d sphere)
{
	if (sphere.x > max->x)
		max->x = sphere.x;
	if (sphere.y > max->y)
		max->y = sphere.y;
	if (sphere.z > max->z)
		max->z = sphere.z;
	if (sphere.x < min->x)
		min->x = sphere.x;
	if (sphere.y < min->y)
		min->y = sphere.y;
	if (sphere.z < min->z)
		min->z = sphere.z;
}

void	ft_get_max_min(t_3d *max, t_3d *min, t_list *object)
{
	t_sphere *sphere;

	object = object->next;
	while (object != NULL)
	{
		sphere = (t_sphere *)(((t_obj *)object->content)->obj);
		ft_change_min_max(min, max, sphere->in);
		object = object->next;
	}
}

void	ft_init_max_min(t_3d *min, t_3d *max)
{
	min->x = 5000000;
	min->y = 5000000;
	min->z = 5000000;
	max->x = -5000000;
	max->y = -5000000;
	max->z = -5000000;
}
