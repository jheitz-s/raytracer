/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:17:26 by tskrzype          #+#    #+#             */
/*   Updated: 2014/03/21 18:35:17 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_init_tab_norm(t_norm *tab_norm)
{
	tab_norm[0].type = 0;
	tab_norm[0].norme = ft_norme_sphere;
	tab_norm[1].type = 1;
	tab_norm[1].norme = ft_norme_plane;
	tab_norm[2].type = 2;
	tab_norm[2].norme = ft_norme_cylinder;
	tab_norm[3].type = 3;
	tab_norm[3].norme = ft_norme_cone;
}

void		ft_normal(t_obj *obj, t_3d *v_prov)
{
	static t_norm	tab_norm[4];
	static int		init = 0;

	if (init == 0)
	{
		ft_init_tab_norm(tab_norm);
		init = 1;
	}
	tab_norm[obj->type].norme(obj->obj, obj->p_inter, &obj->v_normal, v_prov);
}
