/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_in_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htang <htang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 11:27:33 by htang             #+#    #+#             */
/*   Updated: 2014/03/19 09:54:50 by htang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_ch_in_tab(t_read *tab_read, t_obj **obj, char **cf, int *n)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ft_strcmp(tab_read[i].key, cf[*n]) == 0)
			*obj = ft_cr_obj(cf, i, tab_read[i].read_fct, n);
		i++;
	}
}
