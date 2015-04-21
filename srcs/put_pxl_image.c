/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:50:51 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/15 12:37:26 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_put_pxl_image(t_img *img, int color, int x, int y)
{
	int		i;
	char	*color_ptr;

	color_ptr = (char *)(&color);
	i = (x * img->b_pi / 8) + y * img->s_li;
	img->str[i] = color_ptr[0];
	img->str[i + 1] = color_ptr[1];
	img->str[i + 2] = color_ptr[2];
}
