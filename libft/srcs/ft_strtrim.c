/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:54:02 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 13:32:17 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str_new;
	char	*str_ret;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0' && (s[i] == '\n' || s[i] == '\t' || s[i] == ' '))
		i++;
	str_new = ft_strsub(s, i, ft_strlen(s) - i);
	i = ft_strlen(str_new);
	while (i != 0 && (str_new[i - 1] == '\n' || str_new[i - 1] == '\t'
				|| str_new[i - 1] == ' '))
		i--;
	str_new[i] = '\0';
	str_ret = ft_strsub(str_new, 0, ft_strlen(str_new));
	free (str_new);
	str_new = NULL;
	return (str_ret);
}
