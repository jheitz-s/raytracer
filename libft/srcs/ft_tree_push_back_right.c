/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_push_back_right.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 15:06:21 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/02/25 15:12:19 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_push_back_right(t_tree **root, const void *content)
{
	if (*root == NULL)
		*root = ft_tree_new(content);
	else
	{
		if ((*root)->right != NULL)
			ft_tree_push_back_right(&((*root)->right), content);
		else
			(*root)->right = ft_tree_new(content);
	}
}
