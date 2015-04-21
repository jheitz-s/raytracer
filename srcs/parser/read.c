/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 08:45:51 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/23 11:20:28 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_read_sphere(char **cf, t_obj *obj, int *n)
{
	t_sphere	*sphere;
	int			cont;

	sphere = NULL;
	cont = 1;
	if ((sphere = (t_sphere *)malloc(sizeof(t_sphere))) != NULL)
	{
		obj->obj = sphere;
		while (cont)
		{
			*n = *n + 1;
			if (ft_strcmp(cf[*n], "\t!sphere") == 0)
				cont = 0;
			else if (ft_strncmp(cf[*n], "\trayon", ft_strlen("trayon")) == 0)
				ft_get_rayon(cf[*n], &sphere->rayon);
			else if (ft_strncmp(cf[*n], "\tin", ft_strlen("\tin")) == 0)
				ft_get_point(cf[*n], &sphere->in);
		}
	}
}

void	ft_read_cylinder(char **cf, t_obj *obj, int *n)
{
	t_cylinder	*cylinder;
	int			cont;

	cylinder = NULL;
	cont = 1;
	if ((cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))) != NULL)
	{
		obj->obj = cylinder;
		while (cont)
		{
			*n = *n + 1;
			if (ft_strcmp(cf[*n], "\t!cylinder") == 0)
				cont = 0;
			else if (ft_strncmp(cf[*n], "\trayon", ft_strlen("\trayon")) == 0)
				ft_get_rayon(cf[*n], &cylinder->rayon);
			else if (ft_strncmp(cf[*n], "\tin", ft_strlen("\tin")) == 0)
				ft_get_point(cf[*n], &cylinder->in);
			else if (ft_strncmp(cf[*n], "\trotate", ft_strlen("\trotate")) == 0)
				ft_get_point(cf[*n], &cylinder->rotate);
		}
	}
}

void	ft_read_plane(char **cf, t_obj *obj, int *n)
{
	t_plane	*plane;
	int		cont;

	plane = NULL;
	cont = 1;
	if ((plane = (t_plane *)malloc(sizeof(t_plane))) != NULL)
	{
		obj->obj = plane;
		plane->raw = 0;
		while (cont)
		{
			*n = *n + 1;
			if (ft_strcmp(cf[*n], "\t!plane") == 0)
				cont = 0;
			else if (ft_strncmp(cf[*n], "\tin", ft_strlen("tin")) == 0)
				ft_get_point(cf[*n], &plane->in);
			else if (ft_strncmp(cf[*n], "\trotate", ft_strlen("\trotate")) == 0)
				ft_get_point(cf[*n], &plane->rotate);
		}
	}
}

void	ft_read_cone(char **cf, t_obj *obj, int *n)
{
	t_cone		*cone;
	int			cont;

	cone = NULL;
	cont = 1;
	if ((cone = (t_cone *)malloc(sizeof(t_cone))) != NULL)
	{
		obj->obj = cone;
		while (cont)
		{
			*n = *n + 1;
			if (ft_strcmp(cf[*n], "\t!cone") == 0)
				cont = 0;
			else if (ft_strncmp(cf[*n], "\topen", ft_strlen("\topen")) == 0)
				ft_get_rayon(cf[*n], &cone->open);
			else if (ft_strncmp(cf[*n], "\tin", ft_strlen("\tin")) == 0)
				ft_get_point(cf[*n], &cone->in);
			else if (ft_strncmp(cf[*n], "\trotate", ft_strlen("\trotate")) == 0)
				ft_get_point(cf[*n], &cone->rotate);
		}
	}
}
