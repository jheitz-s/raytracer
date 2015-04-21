/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 12:25:58 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 11:46:19 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	ft_init_tab_attr(t_attr *tab_attr)
{
	tab_attr[0].key = ft_strdup("\tcolor");
	tab_attr[0].attr_fct = ft_attr_color;
	tab_attr[1].key = ft_strdup("\ttransparency");
	tab_attr[1].attr_fct = ft_attr_transparency;
	tab_attr[2].key = ft_strdup("\tbrightness");
	tab_attr[2].attr_fct = ft_attr_brightness;
	tab_attr[3].key = ft_strdup("\treflexion");
	tab_attr[3].attr_fct = ft_attr_reflexion;
	tab_attr[4].key = ft_strdup("\tperlin");
	tab_attr[4].attr_fct = ft_attr_perlin;
}

static void	ft_destroy_tab_attr(t_attr *tab_attr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab_attr[i].key);
		i++;
	}
}

static void	ft_read_attribute(char *buf, t_obj *obj)
{
	t_attr	tab_attr[5];
	int		i;

	i = 0;
	ft_init_tab_attr(tab_attr);
	while (i < 5)
	{
		if (ft_strncmp(tab_attr[i].key, buf, ft_strlen(tab_attr[i].key)) == 0)
			tab_attr[i].attr_fct(buf, obj);
		i++;
	}
	ft_destroy_tab_attr(tab_attr, 5);
}

static void	ft_init_obj(t_obj *obj, int type)
{
	obj->type = type;
	obj->obj = NULL;
	obj->brightness = 0;
	obj->transparency = 0;
	obj->reflexion = 0;
	obj->perlin = 0;
	ft_init3d(&obj->p_inter, 0, 0, 0);
	ft_init3d(&obj->v_normal, 0, 0, 0);
	ft_init3d(&obj->color, 255, 255, 255);
}

t_obj		*ft_cr_obj(char **cf, int type,
						void (*fct)(char **, t_obj *, int *), int *n)
{
	t_obj	*obj;
	int		cont;

	obj = NULL;
	cont = 1;
	if ((obj = (t_obj *)malloc(sizeof(t_obj))) != NULL)
	{
		ft_init_obj(obj, type);
		fct(cf, obj, n);
		while (cont == 1)
		{
			*n = *n + 1;
			cont = (ft_strcmp(cf[*n], "!obj") == 0) ? 0 : 1;
			if (cont == 1)
				ft_read_attribute(cf[*n], obj);
		}
	}
	return (obj);
}
