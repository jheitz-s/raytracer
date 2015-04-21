/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 10:25:15 by tskrzype          #+#    #+#             */
/*   Updated: 2014/03/27 17:12:51 by mapetit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		ft_read_pos_rot(char **cf, t_scene *scene, int *n)
{
	*n = *n + 1;
	ft_get_point(cf[*n], &(scene->pos_cam));
	*n = *n + 1;
	ft_get_point(cf[*n], &(scene->rot_cam));
}

void			ft_read_cam(char **cf, t_scene *scene, int *n)
{
	scene->cam = 0;
	*n = *n + 1;
	if (cf[*n] != NULL)
	{
		scene->cam = 1;
		ft_read_pos_rot(cf, scene, n);
	}
}
