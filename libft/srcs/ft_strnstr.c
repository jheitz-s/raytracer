/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:41:32 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 13:30:51 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	m;

	m = ft_strlen(s2);
	i = 0;
	if (m > n)
		return (NULL);
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (ft_strnequ(&(s1[i]), s2, m) && i + m <= n)
			return ((char *)&(s1[i]));
		i++;
	}
	return (NULL);
}
