/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htang <htang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 11:12:59 by htang             #+#    #+#             */
/*   Updated: 2014/03/26 11:42:39 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		ft_cal_dist(t_3d sphere, t_3d other_sphere)
{
	float	dist;
	float	len1;
	float	len2;
	float	len3;

	len1 = sphere.x - other_sphere.x;
	len2 = sphere.y - other_sphere.y;
	len3 = sphere.z - other_sphere.z;
	dist = sqrt(len1 * len1 + len2 * len2);
	dist = sqrt(dist * dist + len3 * len3);
	return ((int)(dist + 1));
}

int		ft_cal_rayon(t_3d sphere, t_list *object)
{
	int			dist;
	int			dist_to_return;
	t_sphere	*other_sphere;

	dist_to_return = 0;
	object = object->next;
	while (object != NULL)
	{
		other_sphere = (t_sphere *)(((t_obj *)object->content)->obj);
		dist = ft_cal_dist(sphere, other_sphere->in) + other_sphere->rayon;
		if (dist > dist_to_return)
			dist_to_return = dist;
		object = object->next;
	}
	return (dist_to_return);
}

void	ft_fill_sphere_glob(t_list **object)
{
	t_3d		max;
	t_3d		min;
	t_sphere	*sphere;
	t_obj		*obj;

	obj = (*object)->content;
	sphere = (t_sphere *)obj->obj;
	ft_init_max_min(&min, &max);
	ft_get_max_min(&max, &min, *object);
	sphere->in.x = (max.x + min.x) / 2;
	sphere->in.y = (max.y + min.y) / 2;
	sphere->in.z = (max.z + min.z) / 2;
	sphere->rayon = ft_cal_rayon(sphere->in, *object);
}

void	ft_s_inter(t_list **inter, t_list **object, char *str, int *n)
{
	if (ft_strcmp(str, "!obj inter") == 0)
	{
		ft_fill_sphere_glob(object);
		ft_list_push_back(inter, *object);
		*object = NULL;
		*n = *n + 1;
	}
}
