/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:44:45 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/17 14:08:55 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tri	*lst;
	t_tri	*start;
	char	**map;
	int		size;
	int		i;

	i = 4;
	size = input(av[1]); 
	lst = NULL;
	map = NULL;
	start = lst;
	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if (ac == 2)
	{
		{
			printf("Taille de la map (ORIGIN): %d\n\n", size);
			map = create_map(size * 4);
			lst = parse(av[1]);
			if (!solving(&lst, map, size, 'A'))
			{
				ft_putendl("1 - Solving -> FAIL\n");
				ft_putendl("2 - Resize map\n");
				size++;
				printf("Taille de la map (RESIZE): %d\n\n", size);
				printf("Piece implacable:\t%c\n", lst->c);
			}
		}
		print_map(map, size);
	}
	return (0);
}
