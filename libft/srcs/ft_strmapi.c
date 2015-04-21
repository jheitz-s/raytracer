/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:14:44 by jheitz-s          #+#    #+#             */
/*   Updated: 2013/11/22 20:19:39 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char(*f)(unsigned int, char))
{
	char			*str;
	unsigned int	z;

	z = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)));
	while (s[z] != '\0')
	{
		str[z] = f(z, *(s + z));
		z++;
	}
	return (str);
}
