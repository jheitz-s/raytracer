/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 17:58:23 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 14:08:06 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <stdlib.h>
# include "rt.h"

typedef void	(*t_ptr_obj)(char **, t_obj *obj, int *n);
typedef void	(*t_ptr_attr)(char *, t_obj *obj);

typedef struct	s_read
{
	char		*key;
	t_ptr_obj	read_fct;
}				t_read;

typedef struct	s_attr
{
	char		*key;
	t_ptr_attr	attr_fct;
}				t_attr;

void			ft_end_obj(t_list *obj, t_list **scene_obj, t_read *tab_read);
void			ft_ch_in_tab(t_read *tab_read, t_obj **obj, char **cf, int *n);
void			ft_s_inter(t_list **inter, t_list **object, char *str, int *n);
char			**ft_save_content_file_tab(int fd);
t_obj			*ft_cr_obj(char **cf, int type,
void			(*p)(char **, t_obj *, int *), int *n);
void			ft_read_sphere(char **cf, t_obj *obj, int *n);
void			ft_read_cylinder(char **cf, t_obj *obj, int *n);
void			ft_read_plane(char **cf, t_obj *obj, int *n);
void			ft_read_cone(char **cf, t_obj *obj, int *n);
void			ft_read_file_spot(char **cf, t_scene *scene, int *n);
t_thread		*ft_parse(char *file);
void			ft_fill_scene_raw(char *attribute, char **mesh, t_scene *scene);
void			ft_init_max_min(t_3d *min, t_3d *max);
void			ft_get_max_min(t_3d *max, t_3d *min, t_list *object);

/*
** Attribute
*/

void			ft_attr_color(char *str, t_obj *obj);
void			ft_attr_transparency(char *str, t_obj *obj);
void			ft_attr_reflexion(char *str, t_obj *obj);
void			ft_attr_brightness(char *str, t_obj *obj);
void			ft_attr_perlin(char *str, t_obj *obj);
void			ft_get_rayon(char *buf, int *rayon);
void			ft_get_point(char *buf, t_3d *point);

#endif
