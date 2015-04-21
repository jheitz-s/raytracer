/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:33:09 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 12:07:05 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_atoi_count(const char *str)
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
	return (nbr);
}

int				ft_atoi(const char *str)
{
	int	i;
	int	sign;

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
	return (ft_atoi_count(&(str[i])) * sign);
}
