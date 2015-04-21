/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 02:50:19 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 12:11:36 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static void		ft_memmove_case_1(char *s1, const char *s2, size_t n)
{
	int	a;

	a = n - 1;
	while (a >= 0)
	{
		*(s1 + a) = *(s2 + a);
		a--;
	}
}

static void		ft_memmove_case_2(char *s1, const char *s2, size_t n)
{
	int	a;

	a = 0;
	while (a < (int)n)
	{
		*(s1 + a) = *(s2 + a);
		a++;
	}
}

void			*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*tmp1;
	const char	*tmp2;

	tmp1 = s1;
	tmp2 = s2;
	if (tmp2 + n >= tmp1 && tmp1 >= tmp2)
		ft_memmove_case_1(s1, s2, n);
	else if (tmp1 + n >= tmp2 && tmp2 >= tmp1)
		ft_memmove_case_2(s1, s2, n);
	else if (tmp2 + n <= tmp1 || tmp1 + n <= tmp2)
		ft_memcpy(s1, s2, n);
	return (s1);
}
