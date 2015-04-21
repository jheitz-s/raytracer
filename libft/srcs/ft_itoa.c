/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:38:21 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 12:08:08 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	chrcounter(int n, int *k)
{
	if (n < 0)
	{
		*k = *k + 1;
		n = -n;
	}
	if (n >= 10)
	{
		chrcounter (n / 10, k);
		chrcounter (n % 10, k);
	}
	else
		*k = *k + 1;
}

static void	put_itoa(char *str, int n, int *k)
{
	if (n < 0)
	{
		str[*k] = '-';
		*k = *k + 1;
		n = -n;
	}
	if (n >= 10)
	{
		put_itoa(str, n / 10, k);
		put_itoa(str, n % 10, k);
	}
	else
	{
		str[*k] = n + 48;
		*k = *k + 1;
	}
}

static void	ft_nbr_min(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
}

char		*ft_itoa(int n)
{
	int		k;
	int		m;
	char	*str;

	k = 0;
	m = 0;
	if (n == -2147483648)
	{
		str = (char *)malloc(sizeof(char) * 12);
		ft_nbr_min(str);
	}
	else
	{
		chrcounter(n, &k);
		str = (char *)malloc(sizeof(char) * k + 1);
		put_itoa(str, n, &m);
		str[k] = '\0';
	}
	return (str);
}
