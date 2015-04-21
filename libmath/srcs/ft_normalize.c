/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 18:40:36 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/10 17:09:57 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void			ft_normalize(t_3d *v)
{
	float	norm;

	norm = ft_norme(v);
	if (norm != 0)
	{
		v->x = v->x / norm;
		v->y = v->y / norm;
		v->z = v->z / norm;
	}
}
