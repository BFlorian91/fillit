/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:44:45 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/10 19:49:22 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tri *lst;
	int fd;
	int i = 0;

	fd = open(av[1], O_RDONLY);
	lst = parsing(fd);
	while (lst != NULL)
	{
		i = 0;
		ft_putchar(lst->c);
		ft_putchar('\n');
		while (i < 4)
		{
			printf("%d [x:%d, y:%d]\n", i, lst->pos[i].x, lst->pos[i].y);
			i++;
		}
		lst = lst->next;
	}
}
