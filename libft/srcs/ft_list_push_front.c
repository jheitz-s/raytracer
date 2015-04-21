/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 15:42:50 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/02/24 16:36:14 by htang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **begin_list, void *content)
{
	t_list	*new_elem;

	if (*begin_list == NULL)
	{
		new_elem = ft_list_new(content);
		*begin_list = new_elem;
	}
	else
	{
		new_elem = ft_list_new(content);
		(*begin_list)->previous = new_elem;
		new_elem->next = *begin_list;
		*begin_list = new_elem;
	}
}
