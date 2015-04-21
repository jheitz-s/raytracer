/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 10:47:29 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/02/25 10:47:31 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * n + 1);
	if (s2)
	{
		while (n != 0)
		{
			s2[i] = s1[i];
			i++;
			n--;
		}
		s2[i] = '\0';
		return (s2);
	}
	else
		return (NULL);
}
