/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htang <htang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 07:28:58 by htang             #+#    #+#             */
/*   Updated: 2014/03/26 14:56:19 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_fill_img(t_env e, t_img *i)
{
	if ((i->img = mlx_new_image(e.mlx, WIDTH, HEIGHT)) != NULL)
		i->str = mlx_get_data_addr(i->img, &i->b_pi, &i->s_li, &i->endi);
	else
	{
		ft_putendl_fd("raytracer: error: can't launch new image", 2);
		return (-1);
	}
	return (0);
}

int			ft_init_img(t_thread *thread)
{
	return (ft_fill_img(thread->e, &thread->img1));
}
