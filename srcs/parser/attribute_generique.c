/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_generique.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 13:38:41 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/25 15:09:21 by mapetit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_attr_color(char *str, t_obj *obj)
{
	char	**split;

	split = NULL;
	split = ft_strsplit(str, ' ');
	ft_init3d(&obj->color, ft_atoi(split[1]), ft_atoi(split[2]),
			ft_atoi(split[3]));
	ft_freesplit(split);
}

void	ft_attr_brightness(char *str, t_obj *obj)
{
	str = ft_strchr(str, ' ') + 1;
	obj->brightness = (float)ft_atoi(str);
}

void	ft_attr_transparency(char *str, t_obj *obj)
{
	str = ft_strchr(str, ' ') + 1;
	obj->transparency = (float)ft_atoi(str);
}

void	ft_attr_reflexion(char *str, t_obj *obj)
{
	str = ft_strchr(str, ' ') + 1;
	obj->reflexion = (float)ft_atoi(str);
}

void	ft_attr_perlin(char *str, t_obj *obj)
{
	str = ft_strchr(str, ' ') + 1;
	obj->perlin = ft_atoi(str);
}
