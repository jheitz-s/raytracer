/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_eq2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 19:11:37 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/13 12:03:20 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libmath.h"

float	ft_solve_eq2(float alpha, float beta, float gama)
{
	float	delta;
	float	tmp1;
	float	tmp2;

	delta = ft_pow(beta, 2) - (4 * alpha * gama);
	if (delta < 0)
		return (-1);
	else if (delta == 0)
		return (-beta / (2 * alpha));
	else
	{
		tmp1 = (-beta - sqrt(delta)) / (2 * alpha);
		tmp2 = (-beta + sqrt(delta)) / (2 * alpha);
		if (tmp1 < 0 && tmp2 > 0)
			return (tmp2);
		else if (tmp1 > 0 && tmp2 < 0)
			return (tmp1);
		else if (tmp1 < 0 && tmp2 < 0)
			return (-1);
		else
			return (-ft_max(-tmp1, -tmp2));
	}
	return (-1);
}
