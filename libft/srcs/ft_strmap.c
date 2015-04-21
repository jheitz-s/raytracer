/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:07:40 by jheitz-s          #+#    #+#             */
/*   Updated: 2013/12/28 02:53:11 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		z;

	z = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)));
	while (s[z] != '\0')
	{
		str[z] = f(*(s + z));
		z++;
	}
	return (str);
}
