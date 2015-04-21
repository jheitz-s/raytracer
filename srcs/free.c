/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 15:33:32 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/12 09:36:16 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_obj_destroy(void *content)
{
	t_obj	*obj;

	obj = (t_obj *)content;
	if (obj->obj != NULL)
		free(obj->obj);
	free(obj);
}

void	ft_destroy_scene(t_scene *scene)
{
	if (scene->object != NULL)
		ft_list_free(&scene->object, &ft_obj_destroy);
	if (scene->spot != NULL)
		ft_list_free(&scene->spot, &ft_obj_destroy);
	free(scene);
}
