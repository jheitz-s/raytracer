/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htang <htang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 07:31:29 by htang             #+#    #+#             */
/*   Updated: 2014/03/26 14:57:23 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	*ft_thread1(void *arg)
{
	t_thread	*thread;

	thread = arg;
	ft_raytracing(thread->scene1, &thread->img1);
	return (NULL);
}

void	*ft_thread2(void *arg)
{
	t_thread	*thread;

	thread = arg;
	ft_raytracing(thread->scene2, &thread->img1);
	return (NULL);
}

void	*ft_thread3(void *arg)
{
	t_thread	*thread;

	thread = arg;
	ft_raytracing(thread->scene3, &thread->img1);
	return (NULL);
}

void	*ft_thread4(void *arg)
{
	t_thread	*thread;

	thread = arg;
	ft_raytracing(thread->scene4, &thread->img1);
	return (NULL);
}
