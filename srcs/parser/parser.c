/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 18:12:12 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/27 16:47:14 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "parser.h"

static void	ft_init_tab_read(t_read *tab_read)
{
	tab_read[0].key = ft_strdup("obj sphere");
	tab_read[0].read_fct = ft_read_sphere;
	tab_read[1].key = ft_strdup("obj plane");
	tab_read[1].read_fct = ft_read_plane;
	tab_read[2].key = ft_strdup("obj cylinder");
	tab_read[2].read_fct = ft_read_cylinder;
	tab_read[3].key = ft_strdup("obj cone");
	tab_read[3].read_fct = ft_read_cone;
}

static void	ft_read_file(char **cf, t_scene *scene, int *n)
{
	t_read	tab_read[4];
	t_obj	*obj;
	t_list	*object;

	object = NULL;
	scene->intersection = NULL;
	scene->object = NULL;
	ft_init_tab_read(tab_read);
	while (cf[*n] != NULL)
	{
		if (*n != 0)
			*n = *n + 1;
		if (scene->nb_alias == 1 && *n == 1)
			*n = *n + 1;
		if (ft_strcmp(cf[*n], "#endobj") == 0)
		{
			ft_end_obj(object, &scene->object, tab_read);
			return ;
		}
		ft_s_inter(&scene->intersection, &object, cf[*n], n);
		ft_ch_in_tab(tab_read, &obj, cf, n);
		ft_list_push_back(&object, obj);
	}
	ft_end_obj(object, &scene->object, tab_read);
}

static void	ft_init_scene(char **cf, t_scene **scene)
{
	int	n;

	n = 0;
	*scene = (t_scene *)malloc(sizeof(t_scene));
	if (ft_strcmp(cf[n], "alias on") == 0)
	{
		n++;
		(*scene)->nb_alias = ft_atoi(cf[n]);
	}
	else
		(*scene)->nb_alias = 0;
	ft_read_file(cf, *scene, &n);
	ft_read_file_spot(cf, *scene, &n);
	ft_read_cam(cf, *scene, &n);
}

t_thread	*ft_parse(char *file)
{
	int			fd;
	char		**content_file;
	t_thread	*thread;

	if ((fd = open(file, O_RDONLY)) >= 0)
	{
		thread = (t_thread *)malloc(sizeof(t_thread));
		thread->scene1 = NULL;
		thread->scene2 = NULL;
		thread->scene3 = NULL;
		thread->scene4 = NULL;
		content_file = ft_save_content_file_tab(fd);
		ft_init_scene(content_file, &thread->scene1);
		ft_init_scene(content_file, &thread->scene2);
		ft_init_scene(content_file, &thread->scene3);
		ft_init_scene(content_file, &thread->scene4);
		ft_freesplit(content_file);
	}
	else
		return (NULL);
	return (thread);
}
