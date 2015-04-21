/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:02:06 by jheitz-s          #+#    #+#             */
/*   Updated: 2013/11/20 15:23:00 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*mem;

	mem = malloc(size);
	if (mem)
	{
		ft_memset(mem, 0, size);
		return (mem);
	}
	else
		return (NULL);
}
