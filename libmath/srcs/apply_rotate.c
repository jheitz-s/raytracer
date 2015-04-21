/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 11:20:43 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/15 15:05:56 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	ft_apply_rotate(t_3d *vec, t_3d rotate)
{
	ft_rotate(vec, rotate.x, 'x');
	ft_rotate(vec, rotate.y, 'y');
	ft_rotate(vec, rotate.z, 'z');
}

void	ft_apply_rotate_rev(t_3d *vec, t_3d rotate)
{
	ft_rotate(vec, -rotate.z, 'z');
	ft_rotate(vec, -rotate.y, 'y');
	ft_rotate(vec, -rotate.x, 'x');
}
