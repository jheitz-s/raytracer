/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 13:50:40 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 12:06:49 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	ft_atoi_count(const char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	return ((float)nbr);
}

static float	ft_atoi_point(const char *str, float nbr)
{
	int	i;
	int	n;

	i = 0;
	n = 10;
	while (str[i] != '.')
		i++;
	i++;
	while (str[i] > 47 && str[i] < 58)
	{
		nbr = nbr + (float)(str[i] - 48) / (float)n;
		i++;
		n *= 10;
	}
	return (nbr);
}

float			ft_atoif(const char *str)
{
	int		i;
	int		sign;
	float	nb;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	while ((str[i] == '+' || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	nb = ft_atoi_count(&(str[i]));
	nb = ft_atoi_point(&(str[i]), nb);
	return (nb * sign);
}
