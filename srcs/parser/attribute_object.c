/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 13:39:28 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/13 11:52:27 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_get_rayon(char *buf, int *rayon)
{
	*rayon = ft_atoi(ft_strchr(buf, ' '));
}

void	ft_get_point(char *buf, t_3d *point)
{
	char	**split;

	split = NULL;
	split = ft_strsplit(buf, ' ');
	if (split[1] && split[2] && split[3] && (split[4] == NULL))
		ft_init3d(point, ft_atoi(split[1]), ft_atoi(split[2]),
				ft_atoi(split[3]));
	ft_freesplit(split);
}
