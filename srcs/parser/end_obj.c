/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htang <htang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 11:44:47 by htang             #+#    #+#             */
/*   Updated: 2014/03/18 12:03:03 by htang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	ft_destroy_tab_read(t_read *tab_read, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&(tab_read[i].key));
		tab_read[i].key = NULL;
		i++;
	}
}

void		ft_end_obj(t_list *obj, t_list **scene_obj, t_read *tab_read)
{
	if (obj != NULL)
		*scene_obj = obj;
	*scene_obj = *scene_obj;
	ft_destroy_tab_read(tab_read, 4);
}
