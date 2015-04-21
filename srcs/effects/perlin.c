/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapetit <mapetit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 11:41:29 by mapetit           #+#    #+#             */
/*   Updated: 2014/03/26 14:59:08 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

static double	rand_noise(int t)
{
	t = (t << 13) ^ t;
	t = (t * (t * t * 15731 + 789221) + 1376312589);
	return (1.0 - (t & 0x7fffffff) / 1073741824.0);
}

double			noise_2d(int x)
{
	int	tmp;

	tmp = rand_noise(x) * 850000;
	return (rand_noise(tmp + x));
}

static double	cosine_interpolate(double a, double b, double t)
{
	double c;

	c = (1 - cos(t * 3.1415927)) * .5;
	return (1. - c) * a + c * b;
}

static double	smooth_noise(double x)
{
	int		int_x;
	double	frac_x;
	double	a;
	double	b;

	if (x >= 0)
		int_x = (int)x;
	else
		int_x = (int)x - 1;
	frac_x = x - int_x;
	a = noise_2d(int_x);
	b = noise_2d(int_x + 1);
	return (cosine_interpolate(a, b, frac_x));
}

double			perlin(int oct, double freq, double pers, double x)
{
	double	r;
	double	f;
	double	amp;
	double	geo_lim;
	int		i;

	r = 0.;
	f = freq;
	amp = 1.;
	i = 0;
	while (i < oct)
	{
		r = r + (smooth_noise((x * f)) * amp);
		amp = amp * pers;
		f = f * 2;
		i++;
	}
	geo_lim = (1 - pers) / (1 - amp);
	return (sin(r * geo_lim));
}
