/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 09:12:49 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/01/17 09:15:49 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_freesplit(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free (split[i]);
		i++;
	}
	free(split);
}
