/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_push_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:50:54 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/02/25 13:58:29 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_push_left(t_tree **root, const void *content)
{
	if (*root == NULL)
		*root = ft_tree_new(content);
	else
		(*root)->left = ft_tree_new(content);
}
