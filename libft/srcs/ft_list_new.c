/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 09:33:03 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 12:08:59 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list		*ft_list_new(void const *content)
{
	t_list		*new_list;

	if ((new_list = (t_list *)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	new_list->content = (void *)content;
	new_list->next = NULL;
	new_list->previous = NULL;
	return (new_list);
}
