/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_spot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapetit <mapetit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:48:46 by mapetit           #+#    #+#             */
/*   Updated: 2014/03/23 13:33:37 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		ft_init_spot(t_spot *spot)
{
	ft_init3d(&spot->p, 0, 0, 0);
	ft_init3d(&spot->color, 255, 255, 255);
}

static void		ft_read_spot_attribute(char *buf, t_spot *spot)
{
	if (ft_strchr(buf, 'i') == NULL)
		ft_get_point(buf, &spot->color);
	else
		ft_get_point(buf, &spot->p);
}

static t_spot	*ft_create_spot(char **cf, int *n)
{
	t_spot	*spot;
	int		cont;

	spot = NULL;
	cont = 1;
	if ((spot = (t_spot *)malloc(sizeof(t_spot))) != NULL)
	{
		ft_init_spot(spot);
		while (cont == 1)
		{
			*n = *n + 1;
			cont = (ft_strcmp(cf[*n], "!spot") == 0) ? 0 : 1;
			if (cont == 1)
				ft_read_spot_attribute(cf[*n], spot);
		}
	}
	return (spot);
}

void			ft_read_file_spot(char **cf, t_scene *scene, int *n)
{
	t_spot	*spot;

	scene->spot = NULL;
	*n = *n + 1;
	while (cf[*n] != NULL)
	{
		if (ft_strcmp(cf[*n], "#endspot") == 0)
			return ;
		spot = ft_create_spot(cf, n);
		ft_list_push_back(&scene->spot, spot);
		*n = *n + 1;
	}
}
