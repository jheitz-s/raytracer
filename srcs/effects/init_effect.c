/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_effect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 11:19:14 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 14:25:18 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_effect(t_scene *scene)
{
	scene->light = 1;
	scene->brightness = 1;
	scene->perlin = 1;
	scene->transparency = 1;
	scene->reflexion = 1;
}
