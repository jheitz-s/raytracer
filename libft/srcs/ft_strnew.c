/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:51:59 by jheitz-s          #+#    #+#             */
/*   Updated: 2013/11/25 15:00:22 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	n;

	n = 0;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str)
	{
		while (n < size + 2)
		{
			str[n] = '\0';
			n++;
		}
		return (str);
	}
	else
		return (NULL);
}
