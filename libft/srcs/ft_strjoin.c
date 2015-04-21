/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:29:44 by jheitz-s          #+#    #+#             */
/*   Updated: 2013/12/25 21:41:50 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;
	int		n;
	int		nb;

	n = 0;
	nb = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	while (s1[n] != '\0')
	{
		str[n] = s1[n];
		n++;
	}
	while (s2[nb] != '\0')
	{
		str[n] = s2[nb];
		nb++;
		n++;
	}
	str[n] = '\0';
	return (str);
}
