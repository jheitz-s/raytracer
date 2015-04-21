/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 17:57:31 by jheitz-s          #+#    #+#             */
/*   Updated: 2014/03/26 15:10:33 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"

int		main(int argc, char **argv)
{
	t_thread	*thread;

	if (argc == 2)
	{
		thread = ft_parse(argv[1]);
		if (thread == NULL)
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		if ((thread->e.mlx = mlx_init()) != NULL)
			ft_init_raytracing(thread);
		else
			ft_putendl_fd("Error: mlx: can't initialize mlx", 2);
	}
	else
		ft_putendl("usage: ./raytracer [scene]");
	return (0);
}
