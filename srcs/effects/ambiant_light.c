/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 10:09:09 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/19 09:08:45 by htang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_ambiant_light(t_3d *color)
{
	color->x = color->x * 0.1;
	color->y = color->y * 0.1;
	color->z = color->z * 0.1;
}
