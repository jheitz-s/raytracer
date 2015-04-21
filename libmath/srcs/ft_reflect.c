/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reflect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 18:58:12 by tskrzype          #+#    #+#             */
/*   Updated: 2014/03/21 14:41:05 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	ft_ray_reflect(t_3d *ray, t_3d *v_normal, t_3d *reflect)
{
	float	cos;

	cos = v_normal->x * ray->x + v_normal->y * ray->y + v_normal->z * ray->z;
	reflect->x = v_normal->x * cos * 2 - ray->x;
	reflect->y = v_normal->y * cos * 2 - ray->y;
	reflect->z = v_normal->z * cos * 2 - ray->z;
}
