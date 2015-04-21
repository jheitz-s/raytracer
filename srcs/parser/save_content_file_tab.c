/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_content_file_tab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htang <htang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 09:06:42 by htang             #+#    #+#             */
/*   Updated: 2014/03/23 12:16:53 by jheitz-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "parser.h"

static int	ft_count_elem(t_list *list_cont_file)
{
	int	n;

	n = 0;
	while (list_cont_file != NULL)
	{
		n++;
		list_cont_file = list_cont_file->next;
	}
	return (n);
}

static char	**ft_change_list_tab(t_list *list_cont_file)
{
	int		nb_elem;
	char	**tab;
	int		n;
	t_list	*list_free;

	nb_elem = ft_count_elem(list_cont_file);
	tab = (char **)malloc(sizeof(char *) * nb_elem + 1);
	tab[nb_elem] = NULL;
	n = 0;
	while (list_cont_file != NULL)
	{
		tab[n] = ft_strdup(list_cont_file->content);
		n++;
		list_free = list_cont_file;
		list_cont_file = list_cont_file->next;
		free(list_free->content);
		free(list_free);
	}
	return (tab);
}

char		**ft_save_content_file_tab(int fd)
{
	t_list	*list_cont_file;
	char	*buf;
	char	**content_file;

	list_cont_file = NULL;
	while (get_next_line(fd, &buf) > 0)
		ft_list_push_back(&list_cont_file, buf);
	if (buf != NULL)
		free(buf);
	content_file = ft_change_list_tab(list_cont_file);
	close(fd);
	return (content_file);
}
