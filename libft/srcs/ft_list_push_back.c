/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 09:32:49 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/02/24 16:31:59 by htang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *content)
{
	t_list	*new_list;

	if (content != NULL)
	{
		if (*begin_list == NULL)
		{
			new_list = ft_list_new(content);
			*begin_list = new_list;
		}
		else
		{
			if ((*begin_list)->next != NULL)
				ft_list_push_back(&((*begin_list)->next), content);
			else
			{
				new_list = ft_list_new(content);
				(*begin_list)->next = new_list;
				new_list->previous = (*begin_list);
			}
		}
	}
}
