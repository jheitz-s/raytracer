/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:01:13 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 12:09:42 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	if (!n)
		return (0);
	while (n && *tmp1 == *tmp2)
	{
		n--;
		(*tmp2)++;
		(*tmp1)++;
	}
	return (*(tmp1 - 1) - *(tmp2 - 1));
}
