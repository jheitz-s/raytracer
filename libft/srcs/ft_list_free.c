/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 08:33:36 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/02/25 09:12:58 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_list_free(t_list **list, void (*fct)(void *))
{
	if (*list != NULL)
	{
		if ((*list)->next != NULL)
			ft_list_free(&((*list)->next), fct);
		fct((*list)->content);
		free(*list);
		*list = NULL;
	}
}
