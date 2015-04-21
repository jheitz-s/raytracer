/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:38:23 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/02/25 13:50:11 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_tree	*ft_tree_new(const void *content)
{
	t_tree	*new_tree;

	new_tree = NULL;
	if ((new_tree = (t_tree *)malloc(sizeof(t_tree))) != NULL)
	{
		new_tree->content = (void *)content;
		new_tree->left = NULL;
		new_tree->right = NULL;
	}
	return (new_tree);
}
