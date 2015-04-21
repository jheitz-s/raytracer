/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:07:09 by jheitz-s          #+#    #+#             */
/*   Updated: 2013/11/22 18:11:47 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	n;
	int	k;

	i = 0;
	n = 0;
	k = 0;
	if (s2[n] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		n = 0;
		k = 0;
		while (s1[i + k] == s2[n] && s2[n] != '\0')
		{
			k++;
			n++;
		}
		if (s2[n] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
