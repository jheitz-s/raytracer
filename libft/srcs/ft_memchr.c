/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:34:26 by jheitz-s          #+#    #+#             */
/*   Updated: 2013/11/23 11:11:38 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*tmp;

	tmp = s;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == c)
			return ((void *)tmp + i);
		i++;
	}
	return (NULL);
}
