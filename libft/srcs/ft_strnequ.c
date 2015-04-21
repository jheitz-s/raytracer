/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:48:02 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 13:30:08 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n && s1[k] == s2[k] && s1[k] != '\0' && s2[k] != '\0')
		k++;
	if (k < n && s1[k] != s2[k])
		return (0);
	return (1);
}
