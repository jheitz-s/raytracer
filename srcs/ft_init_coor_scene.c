/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_coor_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htang <htang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 07:23:52 by htang             #+#    #+#             */
/*   Updated: 2014/03/21 10:19:20 by htang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_coor_scene1(t_scene *scene)
{
	scene->x_beg = 0;
	scene->y_beg = 0;
	scene->x_end = WIDTH / 2;
	scene->y_end = HEIGHT / 2;
}

void	ft_init_coor_scene2(t_scene *scene)
{
	scene->x_beg = 1;
	scene->y_beg = 0;
	scene->x_end = WIDTH;
	scene->y_end = HEIGHT / 2;
}

void	ft_init_coor_scene3(t_scene *scene)
{
	scene->x_beg = 2;
	scene->y_beg = HEIGHT / 2;
	scene->x_end = WIDTH / 2;
	scene->y_end = HEIGHT;
}

void	ft_init_coor_scene4(t_scene *scene)
{
	scene->x_beg = 3;
	scene->y_beg = HEIGHT / 2;
	scene->x_end = WIDTH;
	scene->y_end = HEIGHT;
}
