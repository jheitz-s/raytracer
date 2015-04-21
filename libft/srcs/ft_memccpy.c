/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:47:37 by jheitz-s          #+#    #+#             */
/*   Updated: 2013/11/23 13:26:58 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*tmp1;
	const char	*tmp2;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	while (n--)
	{
		*tmp1 = *tmp2;
		if (*tmp2 == (unsigned char)c)
			return (tmp1 + 1);
		tmp1++;
		tmp2++;
	}
	return (NULL);
}
