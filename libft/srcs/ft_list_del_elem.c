/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:28:09 by tskrzype          #+#    #+#             */
/*   Updated: 2014/03/03 15:46:02 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_list_del_elem(t_list **begin_list, t_list *list, void (*fct)(void *))
{
	t_list	*tmp;

	tmp = *begin_list;
	if (*begin_list == list)
	{
		*begin_list = (*begin_list)->next;
		fct(list->content);
		free(list);
	}
	else
	{
		while (tmp)
		{
			if (tmp == list)
			{
				tmp->previous->next = tmp->next;
				fct(tmp->content);
				free(tmp);
			}
			tmp = tmp->next;
		}
	}
}
