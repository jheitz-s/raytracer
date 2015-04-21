/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:08:27 by jheitz-s          #+#    #+#             */
/*   Updated: 2013/11/22 11:34:31 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n && s1[k] == s2[k] && s1[k] != '\0' && s2[k] != '\0')
		k++;
	if (k < n && s1[k] != s2[k])
		return (s1[k] - s2[k]);
	return (0);
}
