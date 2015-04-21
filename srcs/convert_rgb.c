/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:51:26 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/17 19:58:04 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			ft_secure_color(int color)
{
	int	ret;

	ret = (color < 0) ? 0 : color;
	ret = (color > 255) ? 255 : ret;
	return (ret);
}

void		ft_convert_int(int color, t_3d *color_3d)
{
	color_3d->x = (float)(ft_secure_color((int)(color & 0xff)));
	color_3d->y = (float)(ft_secure_color((int)((color >> 8) & 0xff)));
	color_3d->z = (float)(ft_secure_color((int)((color >> 16) & 0xff)));
}

int			ft_convert_rgb(t_3d color3d)
{
	int		color;
	char	*color_ptr;

	color_ptr = (char *)(&color);
	color_ptr[0] = ft_secure_color((int)color3d.x);
	color_ptr[1] = ft_secure_color((int)color3d.y);
	color_ptr[2] = ft_secure_color((int)color3d.z);
	return (color);
}
