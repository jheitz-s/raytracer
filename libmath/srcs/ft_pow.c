/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 09:23:41 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/01/03 09:52:40 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_pow(float x, int pow)
{
	int		i;
	float	xtmp;

	if (pow == 0)
		return (1);
	i = 1;
	xtmp = x;
	while (i < pow)
	{
		x = x * xtmp;
		i++;
	}
	return (x);
}