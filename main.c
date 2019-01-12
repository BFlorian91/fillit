/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:44:45 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/12 03:22:07 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tri	*lst;
	int		i;

	if (ac == 2)
	{
		if (read_file(av[1]))
		{
			lst = parse(av[1]);
			while (lst != NULL)
			{
				i = 0;
				ft_putchar('\n');
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
		else
			printf("ERROR!\n");
	}
	return (0);
}
