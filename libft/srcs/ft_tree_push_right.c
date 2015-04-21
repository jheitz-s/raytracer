/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_push_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:58:57 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/02/25 14:22:33 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_push_right(t_tree **root, const void *content)
{
	if (*root == NULL)
		*root = ft_tree_new(content);
	else
		(*root)->right = ft_tree_new(content);
}
